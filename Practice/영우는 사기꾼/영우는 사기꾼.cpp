//문제 주소 : https://www.acmicpc.net/problem/14676

#include <iostream>
#include <vector>

int N, M, K;
std::vector<std::vector<int>> LinkInfo;
std::vector<int> InDegree;
std::vector<int> CurConstructInfo; // CurConstructInfo[a] = n // a건물 n개 있음

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M >> K;

	LinkInfo.resize(N + 1);
	InDegree.resize(N + 1);
	for (int i = 0; i < M; ++i)
	{
		int Need, Target;
		std::cin >> Need >> Target;
		LinkInfo[Need].push_back(Target);
		InDegree[Target]++;
	}

	CurConstructInfo.resize(N + 1, 0);
	for (int i = 0; i < K; ++i)
	{
		int Check, Num;
		std::cin >> Check >> Num;

		if (Check == 1)
		{
			if (InDegree[Num] != 0)
			{
				std::cout << "Lier!";
				return 0;
			}

			if (++CurConstructInfo[Num] == 1)
			{
				for (int i = 0; i < LinkInfo[Num].size(); i++)
				{
					InDegree[LinkInfo[Num][i]]--;
				}
			}
		}
		else
		{
			if (CurConstructInfo[Num] <= 0)
			{
				std::cout << "Lier!";
				return 0;
			}

			if (--CurConstructInfo[Num] == 0)
			{
				for (int i = 0; i < LinkInfo[Num].size(); i++)
				{
					InDegree[LinkInfo[Num][i]]++;
				}
			}
		}
	}

	std::cout << "King-God-Emperor";
	return 0;
}