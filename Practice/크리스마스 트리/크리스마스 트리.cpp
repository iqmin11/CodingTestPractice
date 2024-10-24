//문제 주소 : https://www.acmicpc.net/problem/1234

#include <iostream>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, R, G, B;
	std::cin >> N >> R >> G >> B;
	std::vector<std::vector<std::vector<std::vector<unsigned long long>>>> DP(N);
	for (int L = 0; L < N; L++)
	{
		DP[L].resize(R);
		for (int r = 0; r < R; r++)
		{
			DP[L][r].resize(G);
			for (int g = 0; g < G; g++)
			{
				DP[L][r][g].resize(B, -1);
			}
		}
	}

	DP[0][R][G][B] = 1;
	for (int Level = 1; Level <= N; Level++)
	{

	}
	
	//DP[L][R][G][B] += DP[L - 1][R + 1][G][B]
	//DP[L][R][G][B] += DP[L - 1][R][G + 1][B]
	//DP[L][R][G][B] += DP[L - 1][R][G][B + 1]

	//if(L % 2) == 0
	//DP[L][R][G][B] += DP[L - 1][R + 1][G + 1][B];
	//DP[L][R][G][B] += DP[L - 1][R + 1][G][B + 1];
	//DP[L][R][G][B] += DP[L - 1][R][G + 1][B + 1];
	
	//if(L % 3) == 0
	//DP[L][R][G][B] += DP[L - 1][R + 1][G + 1][B + 1];

	return 0;
}