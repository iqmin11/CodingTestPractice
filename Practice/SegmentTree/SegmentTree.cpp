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

	//�� �κ��� ���������� �ʾ���. �ش� ����� �̸� ��ü�� ��� ��������� ǥ��εǾ��־���Ѵٰ� �����߾���
	//ù���. �׸��� �������� �������� ������ �˷��ְ�, ���̰� Ŀ������ ���̳ʸ� Ʈ���� Ư����, ����� ������ ��Ģ������ �� �� �ְ� ��
	int LeftNextIndex = SegCurNode << 1;
	int LeftResult = Init(LeftNextIndex, DataStart, Mid);

	int RightNextIndex = (SegCurNode << 1) + 1;
	int RightResult = Init(RightNextIndex, Mid + 1, DataEnd);
		
	SegmentTree[SegCurNode] = LeftResult + RightResult;
	return SegmentTree[SegCurNode];
}

//�ش� ���׸�Ʈ Ʈ���� Ư¡ ��ü�� ���ڷ� �־���� �ϴ� ������. �����̻��ϱ���
//���������� ����
int FindData(int CurNode, int DataStart, int DataEnd, int Left, int Right) //���� Ž���ϴ� ���, �ش� ����� ���� ������ ~ ����, ���� ã���� �ϴ� ������ ~ ����
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

	return LeftResult + RightResult; //���� ���� ���ϰ� �ֱ� ������ ã�� �����ʹ� ���� �������� ��Ÿ��
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
	SegmentTreeHight = static_cast<int>(std::ceil(std::log2(Data.size()))); //Ʈ���� ����
	SegmentTreeSize = (1 << (SegmentTreeHight + 1)); //Ʈ���� ������ (���̳ʸ� Ʈ�� Ư��)
	SegmentTree.resize(SegmentTreeSize, 0);
	Init(1, 0, Data.size() - 1);

	//�ڵ� ���ش� ������, ������ ���� �ʴ� ����̳׿�.
	int Answer = FindData(1, 0, Data.size() - 1, 0, 2);
	int Differ = 7 - Data[2];

	UpdateData(1,0,Data.size()-1, 2, Differ);

	//����. ���׸�ƮƮ���� �̹� ��������µ�, Ʈ���� Ư¡(�����ε���, ���ε���)�� ���ڷ� �Ź� �־�����ϴ°� ������ �ȵ�, ��� ��ü�� ������������ �ȵǳ�?
	//���߿� ���ĺ� ����...
	return 0;
}