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
};

int main()
{

	Parent P;
	Child C;

	Parent* A = &C;
	Child* B = dynamic_cast<Child*>(A);
	return 0;
}