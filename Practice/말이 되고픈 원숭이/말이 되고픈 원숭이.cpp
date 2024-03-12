//https://www.acmicpc.net/problem/1600

#include <iostream>
#include <vector>
#include <queue>

int K, W, H;
std::vector<std::vector<int>> Grid;

int dx[] = { 1,0,-1,0,-2,-1,1,2,2,1,-1,-2 };
int dy[] = { 0,1,0,-1,-1,-2,-2,-1,1,2,2,1 };

int BFS()
{
	std::pair<int, int> StartPos = { 0,0 };
	std::pair<int, int> DestPos = { W - 1, H - 1 };
	std::vector<std::vector<int>> Depth;
	std::vector<std::vector<int>> KnightMoveCount;
	Depth.resize(H);
	KnightMoveCount.resize(H);
	for (size_t i = 0; i < H; i++)
	{
		Depth[i].resize(W, -1);
		KnightMoveCount[i].resize(W, -1);
	}

	Grid[StartPos.second][StartPos.first] = 1;
	Depth[StartPos.second][StartPos.first] = 0;//깊이
	KnightMoveCount[StartPos.second][StartPos.first] = K; //현재위치에서 남은 Count의 수
	std::queue<std::pair<int, int>> q;
	q.push(StartPos);

	while (!q.empty())
	{
		std::pair<int, int> CurPos = q.front();
		q.pop();

		if (CurPos == DestPos)
		{
			break;
		}

		for (size_t i = 0; i < 12; i++)
		{
			int CheckX = CurPos.first + dx[i];
			int CheckY = CurPos.second + dy[i];

			if (KnightMoveCount[CurPos.second][CurPos.first] <= 0 && i > 3)
			{
				break;
			}

			if (CheckX < 0 || CheckY < 0 || CheckX >= W || CheckY >= H)
			{
				continue;
			}

			if (Grid[CheckY][CheckX] != 0)
			{
				continue;
			}

			Grid[CheckY][CheckX] = 1;
			Depth[CheckY][CheckX] = Depth[CurPos.second][CurPos.first] + 1;
			q.push({ CheckX, CheckY });

			if (i > 3)
			{
				KnightMoveCount[CheckY][CheckX] = KnightMoveCount[CurPos.second][CurPos.first] - 1;
			}
			else
			{
				KnightMoveCount[CheckY][CheckX] = KnightMoveCount[CurPos.second][CurPos.first];
			}
		}
	}

	return Depth[DestPos.second][DestPos.first];
}

int main()
{
	std::cin >> K >> W >> H;
	Grid.resize(H);
	for (size_t y = 0; y < H; y++)
	{
		Grid[y].resize(W);
		for (size_t x = 0; x < W; x++)
		{
			std::cin >> Grid[y][x];	
		}
	}

	std::cout << BFS();
}