//문제 주소 : https://www.acmicpc.net/problem/2293

#include <iostream>
#include <map>
#include <set>
#include <vector>

int DP[100001] = {0, };

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int n, k;
	std::cin >> n >> k;

	std::vector<int> CoinCase;
	CoinCase.resize(n);

	for (int i = 0; i < n; i++)
	{
		std::cin >> CoinCase[i];
	}

	DP[0] = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = CoinCase[i]; j <= k; j++)
		{
			DP[j] += DP[j - CoinCase[i]];
		}
	}

	std::cout << DP[k];

	return 0;
}