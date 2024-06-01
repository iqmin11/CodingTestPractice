//문제 주소 : https://www.acmicpc.net/problem/2638

#include <iostream>
#include <vector>
#include <set>
#include <queue>

int X, Y;
std::vector<std::vector<int>> Grid;
std::vector<std::vector<bool>> IsVisit;
std::vector<std::vector<int>> Surface;
std::set<std::pair<int, int>> Melt;
int CheaseCount = 0;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

void DebugRender()
{
	std::cout << "///////////////////////////////" << std::endl;

	for (int y = 0; y < Y; y++)
	{
		for (int x = 0; x < X; x++)
		{
			std::cout << Surface[y][x];
		}
		std::cout << std::endl;
	}

	std::cout << "///////////////////////////////" << std::endl;
}

//해당 격자로 들어가려고 하는 시도 자체를 체크해서 2개 이상이면...
void BFS(std::pair<int, int> CurIndex)
{
	std::queue<std::pair<int, int>> q;
	IsVisit[CurIndex.second][CurIndex.first] = true;
	q.push(CurIndex);

	while (!q.empty())
	{
		std::pair<int, int> CurIndex = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{

			int CheckX = CurIndex.first + dx[i];
			int CheckY = CurIndex.second + dy[i];

			if (CheckX < 0 || CheckY < 0 || CheckX >= X || CheckY >= Y)
			{
				continue;
			}

			if (Grid[CheckY][CheckX] == 1)
			{
				++Surface[CheckY][CheckX];

				if (Surface[CheckY][CheckX] == 2)
				{
					Melt.insert(std::make_pair(CheckX, CheckY));
				}
				continue;
			}

			if (IsVisit[CheckY][CheckX] == true)
			{
				continue;
			}

			q.push(std::make_pair(CheckX, CheckY));
			IsVisit[CheckY][CheckX] = true;
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> Y >> X;

	Grid.resize(Y);
	IsVisit.resize(Y);
	Surface.resize(Y);

	for (int y = 0; y < Y; y++)
	{
		Grid[y].resize(X, 0);
		IsVisit[y].resize(X, false);
		Surface[y].resize(X, 0);
		for (int x = 0; x < X; x++)
		{
			std::cin >> Grid[y][x];
			if (Grid[y][x] == 1)
			{
				CheaseCount++;
			}
		}
	}

	std::vector<std::vector<bool>> InitVisit = IsVisit;
	std::vector<std::vector<int>> InitSurface = Surface;

	int Answer = 0;

	while (CheaseCount != 0)
	{
		Answer++;

		IsVisit = InitVisit;
		Surface = InitSurface;

		BFS(std::make_pair(0, 0));
		for (auto& i : Melt)
		{
			Grid[i.second][i.first] = 0;
			--CheaseCount;
		}
		Melt.clear();
	}
	
	std::cout << Answer;


	return 0;
}