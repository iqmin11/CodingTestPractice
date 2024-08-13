//문제 주소 : https://www.acmicpc.net/problem/9465

#include <iostream>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	//한줄이라면
	//DP[i] = std::max(DP[i - 1], DP[i - 2] + Arr[i]);

	int T;
	std::cin >> T;
	while (T-- > 0)
	{
		int N;
		std::cin >> N;

		std::vector<std::vector<int>> Sticker;
		Sticker.resize(2);

		for (int y = 0; y < 2; y++)
		{
			Sticker[y].resize(N);
			for (int x = 0; x < N; x++)
			{
				std::cin >> Sticker[y][x];
			}
		}

		if (N == 1)
		{
			std::cout << std::max(Sticker[0][0], Sticker[1][0]) << '\n';
			continue;
		}

		std::vector<std::vector<int>> DP;

		DP.resize(2);
		for (int i = 0; i < 2; i++)
		{
			DP[i].resize(N, 0);
		}

		DP[0][0] = Sticker[0][0];
		DP[1][0] = Sticker[1][0];
		DP[0][1] = DP[1][0] + Sticker[0][1];
		DP[1][1] = DP[0][0] + Sticker[1][1];

		for (int i = 2; i < N; i++)
		{
			DP[0][i] = std::max(DP[1][i - 1] + Sticker[0][i], DP[1][i - 2] + Sticker[0][i]);
			DP[1][i] = std::max(DP[0][i - 1] + Sticker[1][i], DP[0][i - 2] + Sticker[1][i]);
		}

		std::cout << std::max(DP[0][N - 1], DP[1][N - 1]) << '\n';
	}

	return 0;
}