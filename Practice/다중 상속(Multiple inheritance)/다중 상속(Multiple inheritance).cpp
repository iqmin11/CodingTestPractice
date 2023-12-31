#include <iostream>

struct Base
{
	virtual void Function()
	{
		std::cout << "Base Func" << std::endl;
	}
};

struct DerivedLeft : Base
{
	void Function() override
	{
		std::cout << "DerivedLeft Func" << std::endl;
	}
};

struct DerivedRight : Base
{
	void Function() override
	{
		std::cout << "DerivedRight Func" << std::endl;
	}
};

struct MultipleDerived : DerivedLeft, DerivedRight
{
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
	//Base* BasePtr = MultipleDerivedPtr; //Base클래스의 모호성이 생김(Diamond Problem)

	return 0;
}