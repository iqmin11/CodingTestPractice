#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

int N, M;
std::vector<int> Arr;
std::map<std::pair<int, int>, std::pair<int, int>> SegmentTree; // Index Start, Index End /  Min, Max

std::pair<int, int> Init(int Start, int End)
{
	std::pair<int, int> StoE = std::make_pair(Start, End);
	if (Start == End)
	{
		SegmentTree[StoE] = std::make_pair(Arr[Start], Arr[End]);
		return SegmentTree[StoE];
	}
	int mid = (Start + End) / 2;

	std::pair<int, int> FrontResult = Init(Start, mid);
	std::pair<int, int> BackResult = Init(mid + 1, End);
	SegmentTree[StoE] = std::make_pair
	(
		std::min(FrontResult.first, BackResult.first),
		std::max(FrontResult.second, BackResult.second)
	);
	return SegmentTree[StoE];
}

std::pair<int, int> FindValue(int _FindStart, int _FindEnd, int _Left, int _Right)
{

}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;

	Arr.resize(N);

	for (size_t i = 0; i < N; i++)
	{
		std::cin >> Arr[i];
	}

	Init(0, N - 1);



	return 0;
}


//std::vector<std::pair<int, int>> Arr; //index, value
//
//std::pair<int, int> FindMinMax(std::pair<int, int> _StoE)
//{
//	int Min = -1;
//	int Max = -1;
//
//	for (size_t i = 0; i < N; i++)
//	{
//		if (Min != -1 && Max != -1)
//		{
//			break;
//		}
//
//		if (_StoE.first <= Arr[i].first && Arr[i].first <= _StoE.second && Min == -1)
//		{
//			Min = Arr[i].second;
//		}
//
//		if (_StoE.first <= Arr[(N - 1) - i].first && Arr[(N - 1) - i].first <= _StoE.second && Max == -1)
//		{
//			Max = Arr[(N - 1) - i].second;
//		}
//	}
//
//	return std::make_pair(Min, Max);
//}
//
//int main()
//{
//	std::ios_base::sync_with_stdio(false);
//	std::cin.tie(NULL);
//	std::cout.tie(NULL);
//
//	std::cin >> N >> M;
//	
//	Arr.resize(N);
//
//	for (size_t i = 0; i < N; i++)
//	{
//		Arr[i].first = i;
//		std::cin >> Arr[i].second;
//	}
//
//	std::sort(Arr.begin(), Arr.end(), [](std::pair<int, int> left, std::pair<int, int> right)
//		{
//			return left.second < right.second;
//		});
//
//	std::vector<std::pair<int, int>> Answer;
//	Answer.reserve(M);
//
//	for (size_t i = 0; i < M; i++)
//	{
//		int StartIndex, EndIndex;
//		std::cin >> StartIndex >> EndIndex;
//		Answer.push_back(FindMinMax(std::make_pair(StartIndex - 1, EndIndex - 1)));
//	}
//
//	for (size_t i = 0; i < M; i++)
//	{
//		std::cout << Answer[i].first << " " << Answer[i].second << "\n";
//	}
//}