//https://www.acmicpc.net/problem/15989

#include <iostream>
#include <vector>

int DP[10001][4] = { {0,}, {0,} };
//DP[i][1] = DP[i - 1][1];
//DP[i][2] = DP[i - 2][1] + DP[i - 2][2];
//DP[i][3] = DP[i - 3][1] + DP[i - 3][2] + DP[i - 3][3];

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	DP[1][1] = 1;
	DP[1][2] = 0;
	DP[1][3] = 0;
	DP[2][1] = 1;
	DP[2][2] = 1;
	DP[2][3] = 0;
	DP[3][1] = 1;
	DP[3][2] = 1;
	DP[3][3] = 1;

	for (int i = 4; i <= 10000; i++)
	{
		DP[i][1] = DP[i - 1][1];
		DP[i][2] = DP[i - 2][1] + DP[i - 2][2];
		DP[i][3] = DP[i - 3][1] + DP[i - 3][2] + DP[i - 3][3];
	}

	int T;
	std::cin >> T;
	std::vector<int> Answer;
	Answer.resize(T);

	for (int i = 0; i < T; i++)
	{
		std::cin >> Answer[i];
	}

	for (int i = 0; i < T; i++)
	{
		std::cout << DP[Answer[i]][1] + DP[Answer[i]][2] + DP[Answer[i]][3] << '\n';
	}

	return 0;
}