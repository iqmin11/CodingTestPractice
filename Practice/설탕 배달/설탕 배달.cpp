//문제 주소 : https://www.acmicpc.net/problem/2839

#include <iostream>

int DP[5001] = { 0, };

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	DP[0] = -1;
	DP[1] = -1;
	DP[2] = -1;
	DP[3] = 1;
	DP[4] = -1;
	DP[5] = 1;

	for (int i = 6; i < 5001; i++)
	{
		if (DP[i - 3] == -1 && DP[i - 5] == -1)
		{
			DP[i] = -1;
			continue;
		}

		if (DP[i - 3] != -1 && DP[i - 5] == -1)
		{
			DP[i] = DP[i - 3] + 1;
			continue;
		}

		if (DP[i - 3] == -1 && DP[i - 5] != -1)
		{
			DP[i] = DP[i - 5] + 1;
			continue;
		}

		DP[i] = std::min(DP[i - 3] + 1, DP[i - 5] + 1);
	}

	int N;
	std::cin >> N;
	std::cout << DP[N];

	return 0;
}