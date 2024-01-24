#include <iostream>
#include <vector>

int MAX_DP[5][5]; //DP[y][x] = (x,y) 결과의 최대값 (단 x+y가 짝수일 경우만입니다)
int min_DP[5][5]; //DP[y][x] = (x,y) 결과의 최소값 (단 x+y가 짝수일 경우만입니다)

int dx[] = { -2,-1, -1, 0 };
int dy[] = { 0, -1, -1,-2 };

int dviax[] = { -1, 0, -1, 0 };
int dviay[] = { 0, -1, 0, -1 };

int main()
{
	int N;
	std::cin >> N;

	std::vector<std::vector<char>> Grid;

	Grid.resize(N);
	for (size_t i = 0; i < N; i++)
	{
		Grid[i].resize(N);
	}

	for (size_t y = 0; y < N; y++)
	{
		for (size_t x = 0; x < N; x++)
		{
			std::cin >> Grid[y][x];
			MAX_DP[y][x] = INT32_MIN;
			min_DP[y][x] = INT32_MAX;
		}
	}

	MAX_DP[0][0] = Grid[0][0] - '0';
	min_DP[0][0] = Grid[0][0] - '0';

	for (size_t i = 2; i < N; i++)
	{
		if (i % 2 != 0)
		{
			continue;
		}
		MAX_DP[i][0] = MAX_DP[i - 2][0];
		MAX_DP[0][i] = MAX_DP[0][i - 2];
		min_DP[i][0] = min_DP[i - 2][0];
		min_DP[0][i] = min_DP[0][i - 2];
		switch (Grid[i - 1][0])
		{
		case '+':
			MAX_DP[i][0] += Grid[i][0] - '0';
			min_DP[i][0] += Grid[i][0] - '0';
			break;
		case '-':
			MAX_DP[i][0] -= Grid[i][0] - '0';
			min_DP[i][0] -= Grid[i][0] - '0';
			break;
		case '*':
			MAX_DP[i][0] *= Grid[i][0] - '0';
			min_DP[i][0] *= Grid[i][0] - '0';
			break;
		default:
			break;
		}

		switch (Grid[0][i - 1])
		{
		case '+':
			MAX_DP[0][i] += Grid[0][i] - '0';
			min_DP[0][i] += Grid[0][i] - '0';
			break;
		case '-':
			MAX_DP[0][i] -= Grid[0][i] - '0';
			min_DP[0][i] -= Grid[0][i] - '0';
			break;
		case '*':
			MAX_DP[0][i] *= Grid[0][i] - '0';
			min_DP[0][i] *= Grid[0][i] - '0';
			break;
		default:
			break;
		}
	}

	for (size_t y = 1; y < N; y++)
	{
		for (size_t x = 1; x < N; x++)
		{
			if ((x + y) % 2 != 0)
			{
				continue;
			}

			for (size_t i = 0; i < 4; i++)
			{
				int Temp_MAX = INT32_MIN;
				int Temp_min = INT32_MAX;
				int CheckX = x + dx[i];
				int CheckY = y + dy[i];
				if (CheckX < 0 || CheckY < 0)
				{
					continue;
				}

				Temp_MAX = MAX_DP[CheckY][CheckX];
				Temp_min = min_DP[CheckY][CheckX];
				int viaX = x + dviax[i];
				int viaY = y + dviay[i];
				switch (Grid[viaY][viaX])
				{
				case '+':
					Temp_MAX += Grid[y][x] - '0';
					Temp_min += Grid[y][x] - '0';
					break;
				case '-':
					Temp_MAX -= Grid[y][x] - '0';
					Temp_min -= Grid[y][x] - '0';
					break;
				case '*':
					Temp_MAX *= Grid[y][x] - '0';
					Temp_min *= Grid[y][x] - '0';
					break;
				default:
					break;
				}

				MAX_DP[y][x] = std::max(Temp_MAX, MAX_DP[y][x]);
				min_DP[y][x] = std::min(Temp_min, min_DP[y][x]);
			}
		}
	}

	std::cout << MAX_DP[N - 1][N - 1] << " " << min_DP[N - 1][N - 1]; 
}