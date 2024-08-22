//문제 주소 : https://www.acmicpc.net/problem/2143

#include <iostream>
#include <vector>
#include <unordered_map>

int PartialSum(const std::vector<int>& SumArr, int Start, int End)
{
	return SumArr[End] - SumArr[Start - 1];
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int T, n, m;

	std::vector<std::vector<int>> Arr(2);
	std::vector<std::vector<int>> Sum(2);

	std::cin >> T >> n;
	Arr[0].resize(n + 1, 0);
	Sum[0].resize(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		std::cin >> Arr[0][i];
	}
	
	for (int i = 1; i <= n; i++)
	{
		Sum[0][i] = Sum[0][i - 1] + Arr[0][i];
	}

	std::cin >> m;
	Arr[1].resize(m + 1);
	Sum[1].resize(m + 1);
	for (int i = 1; i <= m; i++)
	{
		std::cin >> Arr[1][i];
	}

	for (int i = 1; i <= m; i++)
	{
		Sum[1][i] = Sum[1][i - 1] + Arr[1][i];
	}
	
	std::vector<std::unordered_map<int, long long>> NumCount(2);

	for (int ArrIdx = 0; ArrIdx < 2; ArrIdx++)
	{
		const int CurArrSize = Sum[ArrIdx].size() - 1;

		for (int Length = 1; Length <= CurArrSize; Length++) 
		{
			for (int Start = 1; Start <= CurArrSize - (Length - 1); Start++) 
			{
				int End = Start + Length - 1;
				int Result = PartialSum(Sum[ArrIdx], Start, End);
				NumCount[ArrIdx][Result]++;
			}
		}
	}
	
	long long Answer = 0;
	std::unordered_map<int, long long>* Loop = &NumCount[0];
	std::unordered_map<int, long long>* Comp = &NumCount[1];

	if (Loop->size() > Comp->size())
	{
		std::swap(Loop, Comp);
	}

	for (auto LoopIter : *Loop)
	{
		int Num = LoopIter.first;
		int Count = LoopIter.second;

		int FindNum = T - Num;
		auto FindIter = Comp->find(FindNum);
		if (FindIter == Comp->end())
		{
			continue;
		}

		Answer += FindIter->second * Count;
	}

	std::cout << Answer;

	return 0;
}