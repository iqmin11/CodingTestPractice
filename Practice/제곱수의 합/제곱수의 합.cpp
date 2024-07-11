//문제 주소 : https://www.acmicpc.net/problem/1699

#include <iostream>
#include <cmath>

int DP[100001];

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;

	DP[0] = 0;

	for (int i = 1; i <= N; i++)
	{
		DP[i] = i;

		for (int j = 1; j * j <= i; j++)
		{
			DP[i] = std::min(DP[i], DP[i - j * j] + 1);
		}
	}
	
	std::cout << DP[N];

	return 0;
}