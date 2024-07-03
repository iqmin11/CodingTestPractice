//문제 주소 : https://www.acmicpc.net/problem/12920

#include <iostream>
#include <vector>
#include <map>
int N, M;
std::vector<std::vector<int>> LoadInfo;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;
	
	std::vector<std::vector<int>> DP;

	int MaxCount = 0;
	
	LoadInfo.resize(N + 1);
	for (size_t i = 1; i <= N; i++)
	{
		std::vector<int> Temp(3, 0);
		std::cin >> Temp[0] >> Temp[1] >> Temp[2];
		MaxCount += Temp[2];
		LoadInfo[i] = std::move(Temp);
	}

	DP.resize(MaxCount + 1);
	for (size_t i = 0; i <= MaxCount; i++)
	{
		DP[i].resize(M + 1);
	}

	LoadInfo[0] = { 0,0,0 };
	std::vector<int> LoadCount(N + 1, 0);
	for (size_t i = 1; i <= N; i++)
	{
		LoadCount[i] = LoadInfo[i - 1][2] + LoadCount[i - 1];
	}

	for (size_t i = 1; i <= N; i++)
	{
		for (size_t j = 0; j < LoadInfo[i][2]; j++)
		{
			for (size_t w = 1; w <= M; w++)
			{
				int DPIndex = LoadCount[i] + j + 1;
				if (w < LoadInfo[i][0])
				{
					DP[DPIndex][w] = DP[DPIndex - 1][w];
				}
				else
				{
					DP[DPIndex][w] = std::max(DP[DPIndex - 1][w], DP[DPIndex - 1][w - LoadInfo[i][0]] + LoadInfo[i][1]);
				}
			}
		}
	}

	std::cout << DP[MaxCount][M];

	return 0;
}