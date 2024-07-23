//문제 주소 : https://www.acmicpc.net/problem/2146

#include <iostream>
#include <vector>
#include <queue>

int N;
std::vector<std::vector<int>> Grid;
std::vector<std::vector<bool>> IsVisit;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

template<typename T>
void DebugRender(const std::vector<std::vector<T>>& _Grid)
{
	std::cout << "/////////////////////" << std::endl;

	for (size_t y = 0; y < _Grid.size(); y++)
	{
		for (size_t x = 0; x < _Grid[y].size(); x++)
		{
			std::cout << _Grid[y][x] << ' ';
		}
		std::cout << '\n';
	}

	std::cout << "/////////////////////" << std::endl;
}

void Group_BFS(std::pair<int, int> StartNode, int Group)
{
	std::queue<std::pair<int, int>> q;
	IsVisit[StartNode.second][StartNode.first] = true;
	Grid[StartNode.second][StartNode.first] += Group;
	q.push(StartNode);

	while (!q.empty())
	{
		std::pair<int, int> CurNode = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int CheckX = CurNode.first + dx[i];
			int CheckY = CurNode.second + dy[i];

			if (CheckX < 0 || CheckY < 0 || CheckX >= N || CheckY >= N)
			{
				continue;
			}

			if (Grid[CheckY][CheckX] == 0)
			{
				continue;
			}

			if (IsVisit[CheckY][CheckX])
			{
				continue;
			}

			IsVisit[CheckY][CheckX] = true;
			Grid[CheckY][CheckX] += Group;
			q.push(std::make_pair(CheckX, CheckY));
		}
	}
}

int Bridge_BFS(std::pair<int, int> StartNode, int CurGroup)
{
	std::queue<std::pair<std::pair<int, int>, int>> q;
	q.push(std::make_pair(StartNode, 0));

	while (!q.empty())
	{
		std::pair<int, int> CurNode = q.front().first;
		int CurDepth = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int CheckX = CurNode.first + dx[i];
			int CheckY = CurNode.second + dy[i];

			if (CheckX < 0 || CheckY < 0 || CheckX >= N || CheckY >= N)
			{
				continue;
			}

			if (Grid[CheckY][CheckX] == CurGroup)
			{
				continue;
			}

			if (IsVisit[CheckY][CheckX])
			{
				continue;
			}

			if (Grid[CheckY][CheckX] != 0)
			{
				//시작지점에서 만들 수 있는 가장 짧은 다리
				return CurDepth;
			}

			IsVisit[CheckY][CheckX] = true;
			q.push(std::make_pair(std::make_pair(CheckX, CheckY), CurDepth + 1));
		}
	}

	return INT32_MAX;
}

void InitVisit()
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			IsVisit[y][x] = false;
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	Grid.resize(N);
	IsVisit.resize(N);
	for (int i = 0; i < N; i++)
	{
		Grid[i].resize(N);
		IsVisit[i].resize(N, false);
		for (int j = 0; j < N; j++)
		{
			std::cin >> Grid[i][j];
		}
	}

	int Group = 0;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (IsVisit[y][x])
			{
				continue;
			}

			if (Grid[y][x] == 0)
			{
				continue;
			}

			Group_BFS({x,y}, Group++);
		}
	}

	int Answer = INT32_MAX;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			InitVisit();

			if (Grid[y][x] == 0)
			{
				continue;
			}

			Answer = std::min(Answer, Bridge_BFS({ x,y }, Grid[y][x]));
		}
	}

	std::cout << Answer;

	return 0;
}