//문제 주소 : https://www.acmicpc.net/problem/7579

#include <iostream>
#include <vector>

int N, M;
std::vector<std::pair<int, int>> AppInfo;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;

	AppInfo.resize(N + 1);

	for (int i = 1; i <= N; i++)
	{
		std::cin >> AppInfo[i].first;
	}

	int WholeOperation = 0;
	for (int i = 1; i <= N; i++)
	{
		std::cin >> AppInfo[i].second;
		WholeOperation += AppInfo[i].second;
	}

	std::vector<std::vector<int>> DP;
	DP.resize(N + 1);
	for (int i = 0; i <= N; i++)
	{
		DP[i].resize(WholeOperation + 1, 0);
	}

	int MinOper = INT32_MAX;

	for (int i = 1; i <= N; i++)
	{
		for (int w = 0; w <= WholeOperation; w++)
		{
			if (AppInfo[i].second > w)
			{
				DP[i][w] = DP[i - 1][w];
			}
			else
			{
				DP[i][w] = std::max(DP[i - 1][w], DP[i - 1][w - AppInfo[i].second] + AppInfo[i].first);
				if (DP[i][w] >= M)
				{
					MinOper = std::min(MinOper, w);
				}
			}
		}
	}

	std::cout << MinOper;

	return 0;
}