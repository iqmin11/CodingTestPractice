//문제 주소 : https://www.acmicpc.net/problem/2410

#include <iostream>

int DP[1000001];

int main()
{
	int N;
	std::cin >> N;

	int Mod = 1000000000;

	DP[0] = 1;
	for (int i = 1; i < N; i *= 2)
	{
		for (int j = i; j <= N; j++)
		{
			DP[j] = (DP[j] % Mod + DP[j - i] % Mod) % Mod;
		}
	}

	std::cout << DP[N];

	return 0;
}