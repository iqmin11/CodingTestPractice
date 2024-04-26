//문제 주소 : https://www.acmicpc.net/problem/17485

#include <iostream>
#include <vector>

int N, M;
std::vector<std::vector<int>> Grid;
std::vector<std::vector<std::vector<int>>> DP;

int dx[] = { -1, 0, 1 };
int dy[] = { -1, -1, -1 };

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;

	Grid.resize(N + 1);
	DP.resize(N + 1);
	for (int y = 1; y <= N; y++)
	{
		Grid[y].resize(M + 1);
		DP[y].resize(M + 1, std::vector<int>(3, INT32_MAX));
		for (int x = 1; x <= M; x++)
		{
			std::cin >> Grid[y][x];
		}
	}

	for (int x = 0; x <= M; x++)
	{
		for (int Dir = 0; Dir < 3; Dir++)
		{
			DP[1][x][Dir] = Grid[1][x];
		}
	}

	for (int y = 2; y <= N; y++)
	{
		for (int x = 1; x <= M; x++)
		{
			for (int Dir = 0; Dir < 3; Dir++)
			{
				int MinValue = INT32_MAX;

				int CheckX = x + dx[Dir];
				int CheckY = y + dy[Dir];

				if (CheckX < 1 || CheckY < 1 || CheckX >= M + 1 || CheckY >= N + 1)
				{
					continue;
				}
				
				for (int PrevDir = 0; PrevDir < 3; PrevDir++)
				{
					if (PrevDir == Dir)
					{
						continue;
					}

					MinValue = std::min(MinValue, DP[CheckY][CheckX][PrevDir]);
				}
		
				DP[y][x][Dir] = Grid[y][x] + MinValue;
			}
		}
	}
	
	int Answer = INT32_MAX;

	for (int x = 1; x <= M; x++)
	{
		for (int Dir = 0; Dir < 3; Dir++)
		{
			Answer = std::min(Answer, DP[N][x][Dir]);
		}
	}

	std::cout << Answer;

	return 0;
}