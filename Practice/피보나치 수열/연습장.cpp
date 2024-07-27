#include <iostream>
#include <vector>
#include "MyHeader.h"

class AbstractBase
{
public:
	AbstractBase()
	{

	}

	virtual ~AbstractBase() = 0
	{
		std::cout << "Destructor AbstractBase" << std::endl;
	}
};

class Derived : public AbstractBase
{
public:
	Derived()
	{

	}

	~Derived() override
	{
		std::cout << "Destructor Derived" << std::endl;
	}
};

int main()
{
	AbstractBase* Test = new Derived();
	delete Test;

    return 0;
}