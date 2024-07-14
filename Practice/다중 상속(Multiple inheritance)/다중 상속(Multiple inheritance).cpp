#include <iostream>

class Base
{
public:
	virtual void Function()
	{
		std::cout << "Base Func" << std::endl;
	}
};

class DerivedLeft : public Base
{
public:
	void Function() override
	{
		std::cout << "DerivedLeft Func" << std::endl;
	}
};

class DerivedRight : public Base
{
public:
	void Function() override
	{
		std::cout << "DerivedRight Func" << std::endl;
	}
};

class MultipleDerived : public DerivedLeft, public DerivedRight
{
public:
	void Function() override
	{
		std::cout << "MultipleDerived Func" << std::endl;
	}
};

int main() 
{	
	MultipleDerived* MultipleDerivedPtr = new MultipleDerived;

	MultipleDerivedPtr->DerivedLeft::Function(); // 같은 이름의 멤버 변수, 멤버 함수를 사용하게 되면, 모호성이 생기기 때문에 어떤 클래스의 함수를 호출했는지 명시해야함
	MultipleDerivedPtr->DerivedRight::Function(); // 클래스명::을 붙여줌으로, 모호성을 해소

	DerivedLeft* LeftPtr = MultipleDerivedPtr;
	DerivedRight* RightPtr = MultipleDerivedPtr;
	//Base* BasePtr = MultipleDerivedPtr; //Upcasting하는 클래스가 DerivedLeft인지, DerivedRight인지 모호함(Diamond Problem)

	return 0;
}