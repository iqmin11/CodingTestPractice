//문제 주소 : https://www.acmicpc.net/problem/1043

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

int N, M;
std::vector<bool> KnowTrue;
std::vector<std::vector<int>> Partys;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;

	int TruePeopleCount;
	std::cin >> TruePeopleCount;
	KnowTrue.resize(51, false);

	for (size_t i = 0; i < TruePeopleCount; i++)
	{
		int temp;
		std::cin >> temp;
		KnowTrue[temp] = true;
	}

	Partys.resize(M);
	for (size_t i = 0; i < M; i++)
	{
		int PartyPeopleCount;
		std::cin >> PartyPeopleCount;
		Partys[i].resize(PartyPeopleCount);
		for (size_t j = 0; j < PartyPeopleCount; j++)
		{
			std::cin >> Partys[i][j];
		}
		std::sort(Partys[i].begin(), Partys[i].end());
	}

	int Answer = M;

	for (int Party = 0; Party < M; Party++)
	{
		for (auto j : KnowTrue)
		{
			bool IsFind = std::binary_search(Partys[Party].begin(), Partys[Party].end(), j);
			if (IsFind)
			{
				--Answer;
				break;
			}
		}
	}

	std::cout << Answer;

	return 0;
}