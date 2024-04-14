//https://www.acmicpc.net/problem/2042

#include <iostream>
#include <vector>
#include <cmath>


//세그먼트 트리////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//std::vector<long long> Data;
//std::vector<long long> SegmentTree;
//int SegmentTreeHight, SegmentTreeSize;
//
//long long Init(int SegCurNode, int DataStart, int DataEnd)
//{
//	if (DataStart == DataEnd)
//	{
//		SegmentTree[SegCurNode] = Data[DataStart];
//		return SegmentTree[SegCurNode];
//	}
//
//	int Mid = (DataStart + DataEnd) / 2;
//
//	int LeftNextIndex = SegCurNode << 1;
//	long long LeftResult = Init(LeftNextIndex, DataStart, Mid);
//
//	int RightNextIndex = (SegCurNode << 1) + 1;
//	long long RightResult = Init(RightNextIndex, Mid + 1, DataEnd);
//
//	SegmentTree[SegCurNode] = LeftResult + RightResult;
//	return SegmentTree[SegCurNode];
//}
//
//long long SumData(int CurNode, int DataStart, int DataEnd, int Left, int Right)
//{
//	if (Left > DataEnd || Right < DataStart)
//	{
//		return 0;
//	}
//
//	if (Left <= DataStart && DataEnd <= Right)
//	{
//		return SegmentTree[CurNode];
//	}
//
//	int Mid = (DataStart + DataEnd) / 2;
//
//	int LeftNextIndex = CurNode << 1;
//	long long LeftResult = SumData(LeftNextIndex, DataStart, Mid, Left, Right);
//
//	int RightNextIndex = (CurNode << 1) + 1;
//	long long RightResult = SumData(RightNextIndex, Mid + 1, DataEnd, Left, Right);
//
//	return LeftResult + RightResult; 
//}
//
//void UpdateData(int CurNode, int DataStart, int DataEnd, int ChangeDataIndex, long long Differ)
//{
//	if (ChangeDataIndex > DataEnd || ChangeDataIndex < DataStart)
//	{
//		return;
//	}
//
//	SegmentTree[CurNode] += Differ;
//
//	if (DataStart != DataEnd)
//	{
//		int Mid = (DataStart + DataEnd) / 2;
//
//		int LeftNextIndex = CurNode << 1;
//		UpdateData(LeftNextIndex, DataStart, Mid, ChangeDataIndex, Differ);
//
//		int RightNextIndex = (CurNode << 1) + 1;
//		UpdateData(RightNextIndex, Mid + 1, DataEnd, ChangeDataIndex, Differ);
//	}
//	
//	return;
//}
//
//int main()
//{
//	int N, M, K;
//
//	std::cin >> N >> M >> K;
//	Data.resize(N);
//
//	for (int i = 0; i < N; i++)
//	{
//		std::cin >> Data[i];
//	}
//
//	SegmentTreeHight = static_cast<int>(std::ceil(std::log2(N)));
//	SegmentTreeSize = (1 << (SegmentTreeHight + 1)); 
//	SegmentTree.resize(SegmentTreeSize, 0);
//	Init(1, 0, N - 1);
//
//	std::vector<long long> Answer;
//	Answer.reserve(K);
//
//	for (int i = 0; i < M + K; i++)
//	{
//		int a, b;
//		std::cin >> a >> b;
//		long long c;
//		std::cin >> c;
//		if (a == 1)
//		{
//			long long Differ = c - Data[b - 1];
//			Data[b - 1] = c;
//			UpdateData(1, 0, N - 1, b - 1, Differ);
//			//업데이트
//		}
//		else if (a == 2)
//		{
//			Answer.push_back(SumData(1, 0, N - 1, b - 1, c - 1));
//			//구간합
//		}
//	}
//
//	for (int i = 0; i < K; i++)
//	{
//		std::cout << Answer[i] << "\n";
//	}
//}

//펜윅트리////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int N; //데이터의 갯수
int TreeHight;
int TreeSize;
std::vector<long long> Data; //0번 인덱스를 사용하지 않음 1~8에서
std::vector<long long> FenwickTree;

void Update(int Index, long long Value)
{
	while (Index < FenwickTree.size())
	{
		FenwickTree[Index] = FenwickTree[Index] + Value;
		Index = Index + (Index & -Index);
	}
}

void Init()
{
	for (int i = 1; i <= N; i++)
	{
		Update(i, Data[i]);
	}
}

long long Sum(int Index)
{
	long long Result = 0;
	while (Index > 0)
	{
		Result = Result + FenwickTree[Index];
		Index = Index - (Index & -Index);
	}
	return Result;
}

int main()
{
	int M, K;

	std::cin >> N >> M >> K;
	Data.resize(N + 1);

	for (int i = 1; i <= N; i++)
	{
		std::cin >> Data[i];
	}

	TreeHight = static_cast<int>(std::ceil(std::log2(N))); //트리의 높이
	TreeSize = (1 << (TreeHight + 1)); //트리의 사이즈
	FenwickTree.resize(TreeSize);

	Init();

	std::vector<long long> Answer;
	Answer.reserve(K);

	for (int i = 0; i < M + K; i++)
	{
		int a, b;
		std::cin >> a >> b;
		long long c;
		std::cin >> c;
		if (a == 1)
		{
			long long Differ = c - Data[b];
			Data[b] = c;
			Update(b, Differ); //업데이트를 할땐 차이값을 넣어줘야함
			//업데이트
		}
		else if (a == 2)
		{
			Answer.push_back(Sum(c) - Sum(b - 1));
			//구간합
		}
	}

	for (int i = 0; i < K; i++)
	{
		std::cout << Answer[i] << "\n";
	}

	return 0;
}