#include <iostream>
#include <vector>
#include "MyHeader.h"

template <typename T>
class Singleton
{
public:
	virtual ~Singleton()
	{

	}

	static T* GetInst()
	{
		static T Inst;
		return &Inst;
	}

private:
	Singleton()
	{

	}
};

int main()
{
	int* A = Singleton<int>::GetInst();
	int* B = Singleton<int>::GetInst();
	long long* C = Singleton<long long>::GetInst();
	int a = 0;
	return 0;
}