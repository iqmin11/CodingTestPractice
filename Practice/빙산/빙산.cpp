//문제 주소 : https://www.acmicpc.net/problem/2573

#include <iostream>
#include <vector>
#include <queue>

int N, M;

std::vector<std::vector<int>> Grid;
std::vector<std::vector<int>> EffectBuffer;
std::vector<std::vector<bool>> IsVisit;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

void DebugRender()
{
	std::cout << "////////////////////" << std::endl;

	for (size_t y = 0; y < N; y++)
	{
		for (size_t x = 0; x < M; x++)
		{
			std::cout << Grid[y][x];
		}
		std::cout << std::endl;
	}

	std::cout << "////////////////////" << std::endl;
}

void MeltBFS(std::pair<int, int> StartPos)
{
	std::queue<std::pair<int, int>> q;
	IsVisit[StartPos.second][StartPos.first] = true;
	q.push(StartPos);

	while (!q.empty())
	{
		std::pair<int, int> CurPos = q.front();
		q.pop();

		for (size_t i = 0; i < 4; i++)
		{
			int CheckX = CurPos.first + dx[i];
			int CheckY = CurPos.second + dy[i];

			if (CheckX < 0 || CheckY < 0 || CheckX >= M || CheckY >= N)
			{
				continue;
			}

			if (IsVisit[CheckY][CheckX])
			{
				continue;
			}

			if (Grid[CheckY][CheckX] != 0)
			{
				EffectBuffer[CheckY][CheckX]++;
				continue; 
			}

			q.push(std::make_pair(CheckX, CheckY));
			IsVisit[CheckY][CheckX] = true;
		}
	}
}	

std::vector<std::vector<bool>> IsVisitGroup;

void BFSGroup(std::pair<int, int> StartPos)
{
	std::queue<std::pair<int, int>> q;
	IsVisitGroup[StartPos.second][StartPos.first] = true;
	q.push(StartPos);

	while (!q.empty())
	{
		std::pair<int, int> CurPos = q.front();
		q.pop();

		for (size_t i = 0; i < 4; i++)
		{
			int CheckX = CurPos.first + dx[i];
			int CheckY = CurPos.second + dy[i];

			if (CheckX < 0 || CheckY < 0 || CheckX >= M || CheckY >= N)
			{
				continue;
			}

			if (IsVisitGroup[CheckY][CheckX])
			{
				continue;
			}

			if (Grid[CheckY][CheckX] == 0)
			{
				continue;
			}

			q.push(std::make_pair(CheckX, CheckY));
			IsVisitGroup[CheckY][CheckX] = true;
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;

	Grid.resize(N);
	IsVisit.resize(N);
	IsVisitGroup.resize(N);
	EffectBuffer.resize(N);
	int Count = 0;
	for (int y = 0; y < N; y++)
	{
		Grid[y].resize(M);
		IsVisit[y].resize(M, false);
		IsVisitGroup[y].resize(M, false);
		EffectBuffer[y].resize(M, 0);
		for (int x = 0; x < M; x++)
		{
			std::cin >> Grid[y][x];
			if (Grid[y][x] != 0)
			{
				Count++;
			}
		}
	}

	int Answer = 0;
	std::vector<std::vector<bool>> Init = IsVisit;

	while (true)
	{
		int CountGroup = 0;
		IsVisitGroup = Init;

		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < M; x++)
			{
				if (IsVisitGroup[y][x])
				{
					continue;
				}

				if (Grid[y][x] == 0)
				{
					continue;
				}

				CountGroup++;
				if (CountGroup > 1)
				{
					//정답 출력
					std::cout << Answer;
					exit(0);
				}

				BFSGroup({ x,y });
			}
		}

		Answer++;
		IsVisit = Init;

		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < M; x++)
			{
				if (IsVisit[y][x])
				{
					continue;
				}

				if (Grid[y][x] != 0)
				{
					continue;
				}

				MeltBFS({ x,y });
			}
		}

		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < M; x++)
			{
				int Prev = Grid[y][x];
				Grid[y][x] = std::max(Grid[y][x] - EffectBuffer[y][x], 0);
				EffectBuffer[y][x] = 0;

				if (Prev != 0 && Grid[y][x] == 0)
				{
					Count--;
				}

				if (Count == 0)
				{
					std::cout << 0;
					exit(0);
				}
			}
		}
	}

	return 0;
}