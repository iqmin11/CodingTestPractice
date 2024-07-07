//문제 주소 : https://www.acmicpc.net/problem/2096

#include <iostream>
#include <vector>

int N;

int Grid[100000][3];
int DPMax[2][3];
int DPMin[2][3];

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cin >> Grid[i][j];
		}
	}

	for (int i = 0; i < 3; i++)
	{
		DPMax[0][i] = Grid[0][i];
		DPMin[0][i] = Grid[0][i];
	}

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			DPMax[1][j] = INT32_MIN;
			DPMin[1][j] = INT32_MAX;
		}

		for (int j = 0; j < 3; j++)
		{
			for (int k = -1; k <= 1; k++)
			{
				int Check = j + k;
				if (Check < 0 || Check >= 3)
				{
					continue;
				}

				DPMax[1][j] = std::max(DPMax[1][j], DPMax[0][Check] + Grid[i][j]);
				DPMin[1][j] = std::min(DPMin[1][j], DPMin[0][Check] + Grid[i][j]);
			}
		}

		for (int j = 0; j < 3; j++)
		{
			DPMax[0][j] = std::move(DPMax[1][j]);
			DPMin[0][j] = std::move(DPMin[1][j]);
		}
	}

	int AnswerMax = INT32_MIN;
	int AnswerMin = INT32_MAX;
	for (int i = 0; i < 3; i++)
	{
		AnswerMax = std::max(AnswerMax, DPMax[0][i]);
		AnswerMin = std::min(AnswerMin, DPMin[0][i]);
	}

	std::cout << AnswerMax << " " << AnswerMin;

	return 0;
}