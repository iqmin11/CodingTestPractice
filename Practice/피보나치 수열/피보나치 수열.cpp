#include <iostream>

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

int main()
{

	Parent P;
	ChildChild C;

	Parent* A = &C;
	Child* B = dynamic_cast<Child*>(A);

	
	return 0;
}