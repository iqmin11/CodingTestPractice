//문제 주소 : https://www.acmicpc.net/problem/7569

#include <iostream>
#include <vector>
#include <queue>

int X, Y, H;
std::vector<std::vector<std::vector<int>>> Cube;
std::vector<std::vector<std::vector<bool>>> IsVisit;
std::vector<std::vector<std::vector<int>>> Depth;
int dx[] = { 1,0,0,-1,0,0 };
int dy[] = { 0,1,0,0,-1,0 };
int dh[] = { 0,0,1,0,0,-1 };

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> X >> Y >> H;
	Cube.resize(H);
	IsVisit.resize(H);
	Depth.resize(H);
	int WorkCount = 0;
	
	std::queue<std::vector<int>> q;

	for (int h = 0; h < H; h++)
	{
		Cube[h].resize(Y);
		IsVisit[h].resize(Y);
		Depth[h].resize(Y);
		for (int y = 0; y < Y; y++)
		{
			Cube[h][y].resize(X);
			IsVisit[h][y].resize(X, false);
			Depth[h][y].resize(X, 0);
			for (int x = 0; x < X; x++)
			{
				std::cin >> Cube[h][y][x];

				if (Cube[h][y][x] == 0)
				{
					WorkCount++;
				}
				else if (Cube[h][y][x] == 1)
				{
					IsVisit[h][y][x] = true;
					q.push({ x,y,h });
				}
			}
		}
	}

	if (WorkCount == 0)
	{
		std::cout << 0;
		return 0;
	}

	while (!q.empty())
	{
		std::vector<int> CurPos = std::move(q.front());
		q.pop();

		for (int Dir = 0; Dir < 6; Dir++)
		{
			int CheckX = CurPos[0] + dx[Dir];
			int CheckY = CurPos[1] + dy[Dir];
			int CheckH = CurPos[2] + dh[Dir];

			if (CheckX < 0 || CheckY < 0 || CheckH < 0 || CheckX >= X || CheckY >= Y || CheckH >= H)
			{
				continue;
			}

			if (Cube[CheckH][CheckY][CheckX] == -1)
			{
				continue;
			}

			if (IsVisit[CheckH][CheckY][CheckX])
			{
				continue;
			}

			q.push({CheckX, CheckY, CheckH});
			IsVisit[CheckH][CheckY][CheckX] = true;
			Depth[CheckH][CheckY][CheckX] = Depth[CurPos[2]][CurPos[1]][CurPos[0]] + 1;
			
			if (--WorkCount == 0)
			{
				std::cout << Depth[CheckH][CheckY][CheckX];
				return 0;
			}
		}
	}

	std::cout << -1;

	return 0;
}