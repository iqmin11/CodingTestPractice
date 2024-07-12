//문제 주소 : https://www.acmicpc.net/problem/1793

#include <iostream>

int DP[101];

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	DP[1] = 1;
	DP[2] = 3;

	for (int i = 3; i <= 100; i++)
	{
		DP[i] = DP[i - 1] + 2 * DP[i - 2];
	}

	for (int i = 1; i <= 100; i++)
	{
		std::cout << DP[i] << " ";
	}

	return 0;
}