//https://www.acmicpc.net/problem/14502

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

std::vector<std::vector<int>> Grid;
int N, M;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

void DebugRender()
{
	std::cout << "///////////////////////////////////////////////" << std::endl;
	for (size_t i = 0; i < Grid.size(); i++)
	{
		for (size_t j = 0; j < Grid[i].size(); j++)
		{
			std::cout << Grid[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << "///////////////////////////////////////////////" << std::endl;
}

int DFS(std::pair<int, int> StartPos)
{
	Grid[StartPos.second][StartPos.first] = 2;
	int Count = 1;
	//DebugRender();

	for (size_t i = 0; i < 4; i++)
	{
		int CheckX = StartPos.first + dx[i];
		int CheckY = StartPos.second + dy[i];

		if (CheckX < 0 || CheckY < 0 || CheckX >= M || CheckY >= N)
		{
			continue;
		}

		if (Grid[CheckY][CheckX] != 0)
		{
			continue;
		}

		Count += DFS(std::make_pair(CheckX, CheckY));
	}

	return Count;
}

int main()
{
	std::cin >> N >> M;

	Grid.resize(N);

	std::list<std::pair<int, int>> VirusStart;
	std::vector<std::pair<int, int>> NonWall;
	NonWall.reserve(N*M);
	int CountOfWall = 0;

	for (size_t i = 0; i < N; i++)
	{
		Grid[i].reserve(M);
		for (size_t j = 0; j < M; j++)
		{
			int temp;
			std::cin >> temp;

			if (temp == 2)
			{
				VirusStart.push_back(std::make_pair(j,i));
			}

			if (temp == 1)
			{
				++CountOfWall;
			}

			if (temp == 0)
			{
				NonWall.push_back(std::make_pair(j, i));
			}

			Grid[i].push_back(temp);
		}
	}

	//벽세우기
	std::vector<int> Select_NonWall;
	Select_NonWall.resize(NonWall.size(), 1);

	for (size_t i = 0; i < 3; i++)
	{
		Select_NonWall[i] = 0;
	}
	
	int Safe = (N * M) - (CountOfWall + 3);
	int MinVirus = INT32_MAX;

	std::vector<std::vector<int>> Init = Grid;

	do
	{
		//지도 초기화
		Grid = Init;

		//벽 세개 세우기
		int Count = 0;
		for (size_t i = 0; i < Select_NonWall.size(); i++)
		{
			if (Select_NonWall[i] == 0)
			{
				Grid[NonWall[i].second][NonWall[i].first] = 1;
				Count++;
			}

			if (Count == 3)
			{
				break;
			}
		}

		int SumOfVirus = 0;
		for (auto i : VirusStart)
		{
			SumOfVirus += DFS(i); // 모든 시작지점 돌면서 DFS로 바이러스 숫자 세기
		}

		//바이러스 숫자의 최소값 구하기
		MinVirus = std::min(MinVirus, SumOfVirus); 

	} while (std::next_permutation(Select_NonWall.begin(), Select_NonWall.end()));

	std::cout << Safe - MinVirus;
	return 0;
}