//문제 주소 : https://www.acmicpc.net/problem/11660

#include <iostream>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, T;
	std::vector<std::vector<int>> Grid;

	std::cin >> N >> T;
	Grid.resize(N + 1);
	for (int i = 1; i <= N; i++)
	{
		Grid[i].resize(N + 1, 0);
		for (int j = 1; j <= N; j++)
		{
			std::cin >> Grid[i][j];
		}
	}

	std::vector<std::vector<int>> DP = Grid;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 2; j <= N; j++)
		{
			DP[i][j] = DP[i][j - 1] + Grid[i][j];
		}
	}

	for (int i = 0; i < T; i++)
	{
		int x0, y0, x1, y1;
		std::cin >> x0 >> y0 >> x1 >> y1;

		int Answer = 0;

		for (int i = x0; i <= x1; i++)
		{
			Answer += DP[i][y1] - DP[i][y0 - 1];
		}

		std::cout << Answer << '\n';
	}

	return 0;
}