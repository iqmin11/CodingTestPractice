//문제 주소 : https://www.acmicpc.net/problem/1932

#include <iostream>

int N;
int DP[501][500];

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	std::cin >> N;

	for (int Length = 1; Length <= N; Length++)
	{
		for (int i = 0; i < Length; i++)
		{
			std::cin >> DP[Length][i];
		}
	}
	
	int Answer = DP[1][0];

	for (int i = 2; i <= N; i++)
	{
		DP[i][0] += DP[i - 1][0];
		Answer = std::max(Answer, DP[i][0]);
	}

	for (int y = 2; y <= N; y++)
	{
		for (int x = 1; x < y; x++)
		{
			DP[y][x] += std::max(DP[y - 1][x], DP[y - 1][x - 1]);
			Answer = std::max(Answer, DP[y][x]);
		}
	}

	std::cout << Answer;

	return 0;
}