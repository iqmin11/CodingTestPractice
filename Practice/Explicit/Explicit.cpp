#include <iostream>

//explicit Ű����� Ŭ������ �Ͻ��� ����ȯ�� ���´�.
//�׷� Ŭ������ �Ͻ��� ����ȯ�� ��� �����Ǵ°ɱ�?

class ImplicitInt
{
public:
	ImplicitInt()
		: iValue(-1)
	{

	}

	//1. �Ķ���Ͱ� �ִ� ������ 
	ImplicitInt(long long Param)
		: iValue(static_cast<int>(Param))
	{
		std::cout << "Constructor that takes long long Argument" << std::endl;
	}

	//2. ĳ���� ���۷�����
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
	//�⺻ ������
	ExplicitInt()
		: iValue(-1)
	{

	}

	//1. �Ķ���Ͱ� �ִ� ������
	explicit ExplicitInt(long long Param)
		: iValue(static_cast<int>(Param))
	{
		std::cout << "Constructor that takes long long Argument" << std::endl;
	}

	//2. ĳ���� ���۷�����
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
	ImplicitFunc(TestArgument); // LLŸ�� ���ڰ�, ImplicitIntŬ������ �Ͻ��� ����ȯ �Ǿ���.

	ImplicitInt Test(12LL);
	long long TestCasting = Test; // ImplicitIntŬ���� ������, long long Ÿ������ �Ͻ��� ����ȯ �Ǿ���.

	//ExplicitFunc(TestArgument); �Ұ���
	ExplicitFunc(ExplicitInt(TestArgument)); // �̷��� ��� ��

	ExplicitInt TestExPlicit(12LL);
	//TestCasting = TestExPlicit; //�Ұ���
	TestCasting = static_cast<long long>(TestExPlicit); //��������� ĳ������ ����� ��

}