//https://www.acmicpc.net/problem/2166
#include <iostream>
#include <vector>
#include <cmath>

int main()
{
	int N;
	std::cin >> N;

	std::vector<std::pair<long long, long long>> Pos;
	Pos.resize(N);

	for (size_t i = 0; i < N; i++)
	{
		std::cin >> Pos[i].first;
		std::cin >> Pos[i].second;
	}

	long long Cross0 = 0;
	long long Cross1 = 0;
	for (size_t i = 0; i < N; i++)
	{
		int CurIndex = i;
		int NextIndex = i + 1;
		if (NextIndex >= N)
		{
			NextIndex = 0;
		}

		Cross0 += Pos[CurIndex].first * Pos[NextIndex].second;
		Cross1 += Pos[CurIndex].second * Pos[NextIndex].first;
	}

	long double Answer = static_cast<long double>(Cross0 - Cross1) / static_cast<long double>(2.0);

	Answer *= 10;
	Answer = round(Answer);
	Answer /= 10;

	std::cout << std::fixed;
	std::cout.precision(1);
	std::cout << std::abs(Answer);
}