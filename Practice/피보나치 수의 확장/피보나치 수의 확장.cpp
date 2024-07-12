//문제 주소 : https://www.acmicpc.net/problem/1788

#include <iostream>
#include <cmath>

//std::unordered_map<int, int> DP;
int DP[2000001];

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int ZeroIndex = 1000000;

	DP[ZeroIndex] = 0;
	DP[ZeroIndex + 1] = 1;

	int N;
	std::cin >> N;
	int Mod = 1000000000;

	for (int i = 2; i <= N; i++)
	{
		DP[ZeroIndex + i] = (DP[ZeroIndex + i - 1] % Mod + DP[ZeroIndex + i - 2] % Mod) % Mod;
	}

	for (int i = -1; i >= N; i--)
	{
		DP[ZeroIndex + i] = (DP[ZeroIndex + i + 2] % Mod - DP[ZeroIndex + i + 1] % Mod) % Mod;
	}

	if (DP[ZeroIndex + N] > 0)
	{
		std::cout << 1 << '\n';
	}
	else if (DP[ZeroIndex + N] == 0)
	{
		std::cout << 0 << '\n';
	}
	else
	{
		std::cout << -1 << '\n';
	}

	std::cout << std::abs(DP[ZeroIndex + N]);

	return 0;
}