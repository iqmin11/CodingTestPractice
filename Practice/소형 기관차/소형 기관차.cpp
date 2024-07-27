//巩力 林家 : https://www.acmicpc.net/problem/2616

#include <iostream>
#include <vector>

int N, C;
std::vector<int> TrainInfo;
std::vector<int> Sum;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	TrainInfo.resize(N + 1);
	for (int i = 1; i <= N; i++)
	{
		std::cin >> TrainInfo[i];
	}


	Sum.resize(N + 1);
	Sum[1] = TrainInfo[1];
	for (int i = 2; i <= N; i++)
	{
		Sum[i] = TrainInfo[i] + Sum[i - 1];
	}

	std::cin >> C;

	std::vector<std::vector<int>> DP(4); //硅扯巩力
	for (int i = 0; i < DP.size(); i++)
	{
		DP[i].resize(N + 1);
	}

	for (int i = 1; i <= 3; i++)
	{
		for (int j = C; j <= N; j++)
		{
			DP[i][j] = std::max(DP[i][j - 1], DP[i - 1][j - C] + Sum[j] - Sum[j - C]);
		}
	}

	std::cout << DP[3][N];

	return 0;
}