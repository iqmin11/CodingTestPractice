//문제 주소 : https://www.acmicpc.net/problem/11333

#include <iostream>

long long DP[10001];

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	long long Mod = 1000000007;
	DP[3] = 3;

	for (long long i = 6; i < 10001; i += 3)
	{
		long long n = i / 3;
		long long Pow = 1;
		/*for (int j = 0; j < length; j++)
		{

		}*/
		DP[i] = ((DP[3] * DP[i - 3]) % Mod + (2 * n % Mod)) % Mod;
	}

	std::cout << DP[3333];
	int a = 0;

	return 0;
}