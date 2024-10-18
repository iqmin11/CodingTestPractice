//문제 주소 : https://www.acmicpc.net/problem/2568

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int	N;
	std::cin >> N;

	std::vector<std::pair<int, int>> Lines(N);
	std::map<int, bool> IsCut;
	for (int i = 0; i < N; i++)
	{
		std::cin >> Lines[i].first >> Lines[i].second;
		IsCut[Lines[i].first] = true;
	}

	std::sort(Lines.begin(), Lines.end(), [](const std::pair<int, int>& Left, const std::pair<int, int>& Right)
		{
			return Left.second < Right.second;
		});

	std::vector<int> DP; // DP[i] 길이 i의 증가하는 부분수열의 마지막 원소 중 가장 작은 수;
	std::map<int, int> Index;

	for (int i = 0; i < N; i++)
	{
		if (DP.empty() || Lines[i].first > DP.back())
		{
			DP.push_back(Lines[i].first);
			Index[Lines[i].first] = DP.size() - 1;
		}
		else
		{
			auto FindIter = std::lower_bound(DP.begin(), DP.end(), Lines[i].first);
			*FindIter = Lines[i].first;
			Index[Lines[i].first] = std::distance(DP.begin(), FindIter);
		}
	}

	auto StartIter = std::next(Index.find(DP.back()));
	auto RBegin = std::make_reverse_iterator(StartIter);
	int Prev = RBegin->second + 1;
	for (auto CurIter = RBegin; CurIter != Index.rend(); ++CurIter)
	{
		int Cur = CurIter->second;
		if (Prev - 1 == Cur)
		{
			Prev = Cur;
			IsCut[CurIter->first] = false;
		}
	}

	int CutSize = N - DP.size();
	std::cout << CutSize << '\n';
	auto CurIter = IsCut.begin();

	while (CutSize > 0 && CurIter != IsCut.end())
	{
		if (CurIter->second)
		{
			--CutSize;
			std::cout << CurIter->first << '\n';
		}
		CurIter++;
	}

	return 0;
}