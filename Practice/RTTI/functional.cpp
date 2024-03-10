#include <iostream>
#include <functional>
#include <queue>

//�����Լ�
//1. �Ű������� ��ȯ���� �Ѵ� ���� ������ �Լ�
void Function1() 
{
	std::cout << "�Ű������� ��ȯ���� �Ѵ� ���� ������ �Լ�" << std::endl;
}

//2. ��ȯ���� �ִ� ������ �Լ�
bool Function2()
{
	std::cout << "��ȯ���� �ִ� ������ �Լ�" << std::endl;
	return false;
}

//3. �Ű������� �ִ� ������ �Լ�
void Function3(int a, int b)
{
	std::cout << "�Ű������� �ִ� ������ �Լ�" << std::endl;
}

//4. �Ű������� ��ȯ���� ��� �ִ� ������ �Լ�
bool Function4(int a, int b)
{
	std::cout << "�Ű������� ��ȯ���� ��� �ִ� ������ �Լ�" << std::endl;
	return false;
}

//5. ��� �Լ�
class TestClass
{
public:
	void TestClassFunction()
	{
		std::cout << "��� �Լ�" << std::endl;
		a = 5;
		std::cout << a << std::endl;
	}

	static void StaticMemberFunc()
	{
		std::cout << "��� ���� �Լ�" << std::endl;
	}

	int a = 10;
};


int main()
{
	//�Լ������Ϳ� functional�� ���̸� ������� ����
	//�Լ������͸� ����غ���
	
	//�Լ� �������� ��������
	//��ȯ�� (*������)(�Ű�����)
	void (*FuncPtr1)() = Function1;
	bool (*FuncPtr2)() = Function2;
	void (*FuncPtr3)(int, int) = Function3;
	bool (*FuncPtr4)(int, int) = Function4;

	//��� ��
	FuncPtr1();
	bool Boolean = FuncPtr2();
	std::cout << Boolean << std::endl;
	FuncPtr3(1, 3);
	Boolean = FuncPtr4(2, 4);
	std::cout << Boolean << std::endl;

	//����Լ� �׽�Ʈ/////////////////////////////////
	TestClass MyInstance;
	void (TestClass::*FuncPtr5)() = &TestClass::TestClassFunction; //�̷��� ����.. �ٵ� �̷��� ���� � ��ü�� �� �Լ����� ��� �˾�?
	(MyInstance.*FuncPtr5)(); //�̷��� �ϸ� �ȴٳ�, � ��ü�� � �Լ��� ����
	//�׷� �� ���� ������ ����� �����Ѱǰ�? ���� functional�� ��� �ϴ� ������ ���� �� �𸣰ڳ�
	//�ϴ� ���̴� ù��° ���� �������� ������.

	//�����Լ� ���·δ� �翬�� ��� ����
	void (*FuncPtr6)() = &TestClass::StaticMemberFunc;
	FuncPtr6();

	//functional
	//���� 1. �Լ��� �ñ״�ó�� ������� �Լ��� ���� �� ����
	//cf) �Լ��� ����(�ñ״�ó)�� �Լ��� �Ű�����ȭ �������¸� ���ϴ� ��
	std::function<void()> FuncPtr7 = std::bind(&TestClass::TestClassFunction, MyInstance); //����Լ�
	FuncPtr7();
	std::function<bool()> FuncPtr8;
	FuncPtr7 = std::bind(Function1); //����, �Ű����� ���� �Լ�
	FuncPtr7();
	FuncPtr7 = std::bind(Function2); //���ϸ� �ִ� �Լ�
	FuncPtr7(); //��ȯ���� �������� ����� �����ѵ�
	FuncPtr8 = std::bind(Function2);
	Boolean = FuncPtr8(); //�̷��� ������! �����ϰ� ������ �ִ� ������ ������ �׸�ŭ �Ǽ��� ������ �־��
	int a = 0;
	
	std::function<void(int)> FuncPtr9 = std::bind(Function3, 20, std::placeholders::_1); //�̷��� ����ϴ±�
	//placeholder�� ���� ���ڸ� �� �������� ���δ°�
	FuncPtr9(2);//�̷����� ����� �����ϱ���
	//������ ���ڸ�.. �Լ������Ϳ� ���� ������������ ������
	//�����Լ��� �״�� ����� ���� �ְ�.
	//�����Լ��� Ȱ���ؼ� ������ ���ڸ� �־������ �Ļ� �Լ��� ���� ���� �ְ�.
	//���ϰ��� ���ټ��� �ְ�. Ȱ���Ҽ� �ִ� ������ ����.
	
	//���ٽİ��� ȣȯ�� �Ǳ� ������ ������
	FuncPtr7 = std::bind([]()
		{
			std::cout << "���� �԰���" << std::endl;
		});
	FuncPtr7();
	//������ ���׿� functional�� ���� ������ �� �� ����.
}