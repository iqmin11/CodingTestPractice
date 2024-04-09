#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

std::vector<int> Data = { 1,2,3,4,5 };
std::vector<int> SegmentTree;
int SegmentTreeHight, SegmentTreeSize;

int Init(int SegCurNode, int DataStart, int DataEnd)
{
	if (DataStart == DataEnd)
	{
		SegmentTree[SegCurNode] = Data[DataStart];
		return SegmentTree[SegCurNode];
	}

	int Mid = (DataStart + DataEnd) / 2;

	//이 부분이 직관적이지 않았음. 해당 노드의 이름 자체가 어디서 어디까지라는 표기로되어있어야한다고 생각했었음
	//첫노드. 그리고 데이터의 시작점과 끝점을 알려주고, 깊이가 커질수록 바이너리 트리의 특성상, 노드의 범위를 규칙적으로 알 수 있게 됨
	int LeftNextIndex = SegCurNode << 1;
	int LeftResult = Init(LeftNextIndex, DataStart, Mid);

	int RightNextIndex = (SegCurNode << 1) + 1;
	int RightResult = Init(RightNextIndex, Mid + 1, DataEnd);
		
	SegmentTree[SegCurNode] = LeftResult + RightResult;
	return SegmentTree[SegCurNode];
}

//해당 세그먼트 트리의 특징 자체를 인자로 넣어줘야 하는 이유임. 존나이상하긴함
//직관적이지 않음
int FindData(int CurNode, int DataStart, int DataEnd, int Left, int Right) //현재 탐색하는 노드, 해당 노드의 범위 시작점 ~ 끝점, 내가 찾고자 하는 시작점 ~ 끝점
{
	if (Left > DataEnd || Right < DataStart)
	{
		return 0;
	}

	if (Left <= DataStart && DataEnd <= Right)
	{
		return SegmentTree[CurNode];
	}

	int Mid = (DataStart + DataEnd) / 2;

	int LeftNextIndex = CurNode << 1;
	int LeftResult = FindData(LeftNextIndex, DataStart, Mid, Left, Right);

	int RightNextIndex = (CurNode << 1) + 1;
	int RightResult = FindData(RightNextIndex, Mid + 1, DataEnd, Left, Right);

	return LeftResult + RightResult; //구간 합을 구하고 있기 때문에 찾는 데이터는 합의 형식으로 나타남
}

void UpdateData(int CurNode, int DataStart, int DataEnd, int ChangeDataIndex, int Differ)
{
	if (ChangeDataIndex > DataEnd || ChangeDataIndex < DataStart)
	{
		return;
	}

	SegmentTree[CurNode] += Differ;

	if (DataStart != DataEnd)
	{
		int Mid = (DataStart + DataEnd) / 2;

		int LeftNextIndex = CurNode << 1;
		UpdateData(LeftNextIndex, DataStart, Mid, ChangeDataIndex, Differ);

		int RightNextIndex = (CurNode << 1) + 1;
		UpdateData(RightNextIndex, Mid + 1, DataEnd, ChangeDataIndex, Differ);
	}
	else
	{
		Data[ChangeDataIndex] += Differ;
	}

	return; 
}

int main()
{
	SegmentTreeHight = static_cast<int>(std::ceil(std::log2(Data.size()))); //트리의 높이
	SegmentTreeSize = (1 << (SegmentTreeHight + 1)); //트리의 사이즈 (바이너리 트리 특성)
	SegmentTree.resize(SegmentTreeSize, 0);
	Init(1, 0, Data.size() - 1);

	//코드 이해는 했으나, 마음에 들지 않는 방식이네요.
	int Answer = FindData(1, 0, Data.size() - 1, 0, 2);
	int Differ = 7 - Data[2];

	UpdateData(1,0,Data.size()-1, 2, Differ);

	//이유. 세그먼트트리는 이미 만들어졌는데, 트리의 특징(시작인덱스, 끝인덱스)을 인자로 매번 넣어줘야하는게 마음에 안듬, 노드 자체가 가지고있으면 안되나?
	//나중에 고쳐볼 수도...
	return 0;
}