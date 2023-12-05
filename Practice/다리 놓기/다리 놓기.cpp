#include <iostream>
#include <vector>

long long DP[31][31]; // nCr

int main()
{
	for (size_t i = 0; i < 31; i++)
	{
		DP[i][0] = 1;
	}

	DP[1][1] = 1;

	for (size_t n = 1; n <= 30; n++)
	{
		for (size_t r = 1; r <= n; r++)
		{
			DP[n][r] = DP[n - 1][r - 1] + DP[n - 1][r];
		}
	}

	int T, N, M;
	std::cin >> T;
	std::vector<long long> result;
	result.reserve(T);

	for (size_t i = 0; i < T; i++)
	{
		std::cin >> N >> M;
		result.emplace_back(DP[M][N]);
	}

	for (size_t i = 0; i < result.size(); i++)
	{
		std::cout << result[i] << "\n";
	}

	return 0;
}