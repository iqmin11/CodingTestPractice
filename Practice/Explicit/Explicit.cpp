#include <iostream>

//explicit 키워드는 클래스의 암시적 형변환을 막는다.
//그럼 클래스의 암시적 형변환은 어디서 구현되는걸까?

class ImplicitInt
{
public:
	ImplicitInt()
		: iValue(-1)
	{

	}

	//1. 파라미터가 있는 생성자 
	ImplicitInt(long long Param)
		: iValue(static_cast<int>(Param))
	{
		std::cout << "Constructor that takes long long Argument" << std::endl;
	}

	//2. 캐스팅 오퍼레이터
	operator long long()
	{
		std::cout << "long long Cast Operator" << std::endl;
		return static_cast<long long>(iValue);
	}

	int iValue;
};

void ImplicitFunc(ImplicitInt Param)
{
	int a = 0;
}

class ExplicitInt
{
public:
	//기본 생성자
	ExplicitInt()
		: iValue(-1)
	{

	}

	//1. 파라미터가 있는 생성자
	explicit ExplicitInt(long long Param)
		: iValue(static_cast<int>(Param))
	{
		std::cout << "Constructor that takes long long Argument" << std::endl;
	}

	//2. 캐스팅 오퍼레이터
	explicit operator long long()
	{
		std::cout << "long long Cast Operator" << std::endl;
		return static_cast<long long>(iValue);
	}

	int iValue;
};

void ExplicitFunc(ExplicitInt Param)
{
	int a = 0;
}

int main()
{
	long long TestArgument = 10LL;
	ImplicitFunc(TestArgument); // LL타입 인자가, ImplicitInt클래스로 암시적 형변환 되었다.

	ImplicitInt Test(12LL);
	long long TestCasting = Test; // ImplicitInt클래스 변수가, long long 타입으로 암시적 형변환 되었다.

	//ExplicitFunc(TestArgument); 불가능
	ExplicitFunc(ExplicitInt(TestArgument)); // 이렇게 써야 함

	ExplicitInt TestExPlicit(12LL);
	//TestCasting = TestExPlicit; //불가능
	TestCasting = static_cast<long long>(TestExPlicit); //명시적으로 캐스팅을 해줘야 함

}