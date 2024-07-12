//문제 주소 : https://www.acmicpc.net/problem/1904

#include <iostream>

int DP[1000001];

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	DP[1] = 1;
	DP[2] = 2;
	int N;
	std::cin >> N;

	int Mod = 15746;

	for (int i = 3; i <= N; i++)
	{
		DP[i] = (DP[i - 1] % Mod + DP[i - 2] % Mod) % Mod;
	}

	std::cout << DP[N];

	return 0;
}