//문제 주소 : https://www.acmicpc.net/problem/2193

#include <iostream>

unsigned long long DP[91][2]; // DP[a][b] b로 끝나는 a자리 이친수의 갯수

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;

	DP[1][0] = 0;
	DP[1][1] = 1;

	for (int i = 2; i <= N; i++)
	{
		DP[i][0] = DP[i - 1][1] + DP[i - 1][0];
		DP[i][1] = DP[i - 1][0];
	}

	std::cout << DP[N][0] + DP[N][1];

	return 0;
}