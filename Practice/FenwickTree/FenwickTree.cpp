#include <iostream>
#include <vector>
#include <cmath>

int N = 8; //데이터의 갯수
int TreeHight;
int TreeSize;
std::vector<long long> Data = { 0,1,2,3,4,5,6,7,8 }; //0번 인덱스를 사용하지 않음 1~5에서
std::vector<long long> FenwickTree;

void UpdateData(int Index, int Value)
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
		UpdateData(i, Data[i]);
	}
}

int Sum(int Index)
{
	int Result = 0;
	while (Index > 0)
	{
		Result = Result + FenwickTree[Index];
		Index = Index - (Index & -Index);
	}
	return Result;
}

int main()
{
	TreeHight = static_cast<int>(std::ceil(std::log2(N))); //트리의 높이
	TreeSize = (1 << (TreeHight + 1)); //트리의 사이즈
	FenwickTree.resize(TreeSize);
	Init();
	int Answer = Sum(5) - Sum(2); // 3,4,5 

	return 0;
}