//https://www.acmicpc.net/problem/2357

#include <iostream>
#include <vector>
#include <cmath>

int N, M;
std::vector<int> Data;
std::vector<std::pair<int, int>> SegmentTree; //ÃÖ¼Ú°ª, ÃÖ´ñ°ª
int SegmentTreeHight, SegmentTreeSize;

std::pair<int, int> Init(int SegCurNode, int DataStart, int DataEnd)
{
	if (DataStart == DataEnd)
	{
		SegmentTree[SegCurNode].first = Data[DataStart];
		SegmentTree[SegCurNode].second = Data[DataStart];
		return SegmentTree[SegCurNode];
	}

	int Mid = (DataStart + DataEnd) / 2;

	int LeftNextIndex = SegCurNode << 1;
	std::pair<int, int> LeftResult = Init(LeftNextIndex, DataStart, Mid);

	int RightNextIndex = (SegCurNode << 1) + 1;
	std::pair<int, int> RightResult = Init(RightNextIndex, Mid + 1, DataEnd);

	SegmentTree[SegCurNode].first = std::min(LeftResult.first, RightResult.first);
	SegmentTree[SegCurNode].second = std::max(LeftResult.second, RightResult.second);
	return SegmentTree[SegCurNode];
}

std::pair<int, int> FindData(int CurNode, int DataStart, int DataEnd, int Left, int Right)
{
	if (Left > DataEnd || Right < DataStart)
	{
		return std::make_pair(INT32_MAX, INT32_MIN);
	}

	if (Left <= DataStart && DataEnd <= Right)
	{
		return SegmentTree[CurNode];
	}

	int Mid = (DataStart + DataEnd) / 2;

	int LeftNextIndex = CurNode << 1;
	std::pair<int, int> LeftResult = FindData(LeftNextIndex, DataStart, Mid, Left, Right);

	int RightNextIndex = (CurNode << 1) + 1;
	std::pair<int, int> RightResult = FindData(RightNextIndex, Mid + 1, DataEnd, Left, Right);

	return std::make_pair(std::min(LeftResult.first, RightResult.first), std::max(LeftResult.second, RightResult.second));
}

int main()
{
	std::cin >> N >> M;
	Data.resize(N);

	SegmentTreeHight = static_cast<int>(std::ceil(std::log2(Data.size())));
	SegmentTreeSize = (1 << (SegmentTreeHight + 1));
	SegmentTree.resize(SegmentTreeSize, std::make_pair(INT32_MAX, INT32_MIN));

	for (size_t i = 0; i < N; i++)
	{
		std::cin >> Data[i];
	}

	Init(1, 0, Data.size() - 1);
	std::vector<std::pair<int, int>> Answers;
	Answers.reserve(M);
	for (size_t i = 0; i < M; i++)
	{
		int FindStart;
		int FindEnd;
		std::cin >> FindStart >> FindEnd;
		Answers.push_back(FindData(1, 0, Data.size() - 1, FindStart - 1, FindEnd - 1));
	}

	for (size_t i = 0; i < M; i++)
	{
		std::cout << Answers[i].first << " " << Answers[i].second << "\n";
	}

	return 0;
}