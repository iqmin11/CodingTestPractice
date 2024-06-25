//문제 주소 : https://www.acmicpc.net/problem/20057

#include <iostream>
#include <vector>

int N;
std::vector<std::vector<double>> Grid;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

void DebugRender(const std::vector<std::vector<double>>& _Grid)
{
	std::cout << "///////////////////////" << std::endl;
	
	for (size_t y = 0; y < _Grid.size(); y++)
	{
		for (size_t x = 0; x < _Grid[y].size(); x++)
		{
			std::cout << _Grid[y][x] << " ";
		}

		std::cout << std::endl;
	}
	
	std::cout << "///////////////////////" << std::endl;
}

std::vector<std::vector<std::vector<double>>> Effect =
{
	{
		{0,0,0.02,0,0},
		{0,0.10,0.07,0.01,0},
		{0.05,-1,0,0,0},
		{0,0.10,0.07,0.01,0},
		{0,0,0.02,0,0}
	},
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	Grid.resize(N);
	for (int y = 0; y < N; y++)
	{
		Grid[y].resize(N);

		for (int x = 0; x < N; x++)
		{
			std::cin >> Grid[y][x];
		}
	}

	Effect.resize(4);
	for (size_t i = 1; i < 4; i++)
	{
		Effect[i].resize(5);
		for (int y = 0; y < 5; y++)
		{
			Effect[i][y].resize(5);
		}
	}

	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			Effect[2][y][x] = Effect[0][y][4 - x];
		}
	}
	
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			Effect[3][y][x] = Effect[0][x][y];
		}
	}

	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			Effect[1][y][x] = Effect[3][4 - y][x];
		}
	}

	std::pair<int, int> StartPos = {N / 2, N / 2};
	std::pair<int, int> CurPos = StartPos;
	std::pair<int, int> DestPos = { 0,0 };

	int Dist = 1;
	int Dir = 0;
	int Answer = 0;

	while (true)
	{
		for (int i = 0; i < Dist; i++)
		{
			DebugRender(Grid);

			CurPos.first += dx[Dir];
			CurPos.second += dy[Dir];

			double Sand = Grid[CurPos.second][CurPos.first];
			int RemainSand = Sand;

			//토네이도 이펙트 적용
			Grid[CurPos.second][CurPos.first] = 0;
			std::pair<int, int> RemainPos;
			for (int y = -2; y <= 2; y++)
			{
				for (int x = -2; x <= 2; x++)
				{
					int CheckX = CurPos.first + x;
					int CheckY = CurPos.second + y;

					if (Effect[Dir][y + 2][x + 2] == -1)
					{
						RemainPos = std::make_pair(CheckX, CheckY);
						continue;
					}

					int BlowSand = Sand * Effect[Dir][y + 2][x + 2];
					RemainSand -= BlowSand;

					if (CheckX < 0 || CheckY < 0 || CheckX >= N || CheckY >= N)
					{
						Answer += BlowSand;
						continue;
					}

					Grid[CheckY][CheckX] += BlowSand;
				}
			}

			if (RemainPos.first < 0 || RemainPos.second < 0 || RemainPos.first >= N || RemainPos.second >= N)
			{
				Answer += RemainSand;
			}
			else
			{
				Grid[RemainPos.second][RemainPos.first] = RemainSand;
			}

			if (CurPos == DestPos)
			{
				//답안 제출

				exit(0);
			}
		}

		Dir = (Dir + 1) % 4;

		if (Dir == 0 || Dir == 2)
		{
			Dist++;
		}
	}

	return 0;
}