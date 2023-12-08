#include <iostream>
#include <vector>
#include <set>
#include <list>

int DP[100001];

class Parent
{
public:
	virtual void Test()
	{
		int a = 0;
	}
	
};

class Child : public Parent
{
public:
	void Test() override
	{
		int a = 0;
	}

	virtual void AA()
	{

	}
};

class ChildChild : public Child
{
public:
	void Test() override
	{
		int a = 0;
	}

	void AA() override
	{
		int a = 0;
	}
};

std::vector<std::set<int>> LinkNodes = { {1,2,3}, {0,2,3}, {0,1,3}, {0,1,2} };
std::vector<bool> IsVisit = {false, false, false, false};
std::vector<int> PrintStack;

void DFS_Combination(int _Start, int _r) // 순열
{
	IsVisit[_Start] = true;
	PrintStack.push_back(_Start);

	if (PrintStack.size() == _r)
	{
		for (size_t i = 0; i < PrintStack.size(); i++)
		{
			std::cout << PrintStack[i] << ' ';
		}
		std::cout << std::endl;

		PrintStack.pop_back();
		IsVisit[_Start] = false;
		return;
	}

	for (auto& LinkNode : LinkNodes[_Start])
	{
		if (!IsVisit[LinkNode] && LinkNode > PrintStack.back())
		{
			DFS_Combination(LinkNode, _r);
		}
	}

	PrintStack.pop_back();
	IsVisit[_Start] = false;
}

void Combination(int _n, int _r)
{
	for (size_t i = 0; i < _n; i++)
	{
		DFS_Combination(i, _r);
	}
}

void DFS_Permutation(int _Start, int _r) // 순열
{
	IsVisit[_Start] = true;
	PrintStack.push_back(_Start);

	if (PrintStack.size() == _r)
	{
		for (size_t i = 0; i < PrintStack.size(); i++)
		{
			std::cout << PrintStack[i] << ' ';
		}
		std::cout << std::endl;

		PrintStack.pop_back();
		IsVisit[_Start] = false;
		return;
	}

	for (auto& LinkNode : LinkNodes[_Start])
	{
		if (!IsVisit[LinkNode])
		{
			DFS_Combination(LinkNode, _r);
		}
	}

	PrintStack.pop_back();
	IsVisit[_Start] = false;
}

void Permutation(int _n, int _r)
{
	for (size_t i = 0; i < _n; i++)
	{
		DFS_Permutation(i, _r);
	}
}

int main()
{

	Parent P;
	ChildChild C;

	Parent* A = &C;
	Child* B = dynamic_cast<Child*>(A);

	Permutation(4, 2);

	return 0;
}