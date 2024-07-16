//문제 주소 https://www.acmicpc.net/problem/7576

#include <iostream>
#include <vector>
#include <queue>

int X, Y;
std::vector<std::vector<int>> Grid;
std::vector<std::pair<int, int>> StartPos;
int ZeroCount = 0;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int BFS()
{
	std::queue<std::pair<int, int>> q;
	std::pair<int, int> LastCheckNode;

	for (int i = 0; i < StartPos.size(); i++)
	{
		LastCheckNode = StartPos[i];
		q.push(StartPos[i]);
	}

	while (!q.empty())
	{
		std::pair<int, int> CurNode = q.front();
		q.pop();
		LastCheckNode = CurNode;

		for (int i = 0; i < 4; i++)
		{
			int CheckX = CurNode.first + dx[i];
			int CheckY = CurNode.second + dy[i];

			if (CheckX < 0 || CheckY < 0 || CheckX >= X || CheckY >= Y)
			{
				continue;
			}

			if (Grid[CheckY][CheckX] != 0)
			{
				continue;
			}

			q.push(std::make_pair(CheckX, CheckY));
			Grid[CheckY][CheckX] = Grid[CurNode.second][CurNode.first] + 1;
			ZeroCount--;
		}
	}

	if (ZeroCount > 0)
	{
		return -1;
	}

	return Grid[LastCheckNode.second][LastCheckNode.first] - 1;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> X >> Y;
	Grid.resize(Y);
	for (int y = 0; y < Y; y++)
	{
		Grid[y].resize(X);

		for (int x = 0; x < X; x++)
		{
			std::cin >> Grid[y][x];

			if (Grid[y][x] == 1)
			{
				StartPos.push_back(std::make_pair(x, y));
			}
			else if (Grid[y][x] == 0)
			{
				++ZeroCount;
			}
		}
	}

	std::cout << BFS();

	return 0;
}