#include <iostream>
#include <vector>
#include <cmath>

int N = 8; //�������� ����
int TreeHight;
int TreeSize;
std::vector<long long> Data = { 0,1,2,3,4,5,6,7,8 }; //0�� �ε����� ������� ���� 1~8���� �������� �������� ������� �Ѱ� ŭ
std::vector<long long> FenwickTree;

void Update(int Index, long long Value) //���� �ʱ�ȭ���� ���� ������ ������Ʈ ���� ���̾���, ������Ʈ�� ���̰��� �־�� ��
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
	TreeHight = static_cast<int>(std::ceil(std::log2(N))); //Ʈ���� ����
	TreeSize = (1 << (TreeHight + 1)); //Ʈ���� ������
	FenwickTree.resize(TreeSize);
	Init();
	long long Answer = Sum(5) - Sum(2); // 3,4,5 

	return 0;
}