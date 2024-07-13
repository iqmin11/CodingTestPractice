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

	MultipleDerivedPtr->DerivedLeft::Function(); // ���� �̸��� ��� ����, ��� �Լ��� ����ϰ� �Ǹ�, ��ȣ���� ����� ������ � Ŭ������ �Լ��� ȣ���ߴ��� ����ؾ���
	MultipleDerivedPtr->DerivedRight::Function(); // Ŭ������::�� �ٿ�������, ��ȣ���� �ؼ�

	DerivedLeft* LeftPtr = MultipleDerivedPtr;
	DerivedRight* RightPtr = MultipleDerivedPtr;
	//Base* BasePtr = MultipleDerivedPtr; //Upcasting�ϴ� Ŭ������ DerivedLeft����, DerivedRight���� ��ȣ��(Diamond Problem)

	return 0;
}