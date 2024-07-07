//문제 주소 : https://www.acmicpc.net/problem/1309

#include <iostream>

int DP[100001];

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;

	DP[1] = 3;
	DP[2] = 7;
	int Mod = 9901;

	for (int i = 3; i <= N; i++)
	{
		DP[i] = (2 * DP[i - 1] % Mod + DP[i - 2] % Mod) % Mod;
	}

	std::cout << DP[N];

	return 0;
}