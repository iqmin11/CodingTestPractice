//문제 주소 : https://www.acmicpc.net/problem/2133

#include <iostream>
#include <vector>

long long DP[16];

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;
	int Half = N / 2;
	if (Half * 2 != N)
	{
		std::cout << 0;
		return 0;
	}

	DP[0] = 1;
	DP[1] = 3;

	for (int i = 2; i <= Half; i++)
	{
		DP[i] += DP[1] * DP[i - 1];
		for (int j = 0; j <= i - 2; j++)
		{
			DP[i] += 2 * DP[j];
		}
	}

	std::cout << DP[Half];

	return 0;
}