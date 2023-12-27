#include <typeinfo> //RTTI��� �� typeid �����ڿ� type_info Ŭ������ ����ϱ� ���� ���
#include <iostream>

class Base
{
public:
	virtual ~Base()
	{

	}
};

class Derived : public Base
{
public:
	~Derived() override
	{

	} 
};

int main()
{
	Derived* derivedPtr = new Derived();
	Base* UpcastPtr = derivedPtr;
	Base* BasePtr = new Base();
	Derived* DowncastPtr = dynamic_cast<Derived*>(UpcastPtr);

	const std::type_info& confirm = typeid(*UpcastPtr); //typeid �����ڴ� const type_info& ���·� ��ü ������ ��ȯ
	//1. �����Լ� ���̺� üũ�� ���ؼ� �ش� ��ü�� ���� Ȯ���ϱ� ������, �����Լ����̺��� ���ٸ� ������ Ŭ������ Ȯ�� ����(Base�� �޾Ҵٸ� Base�� ��ȯ)
	//2. �����Լ� ���̺��� �ִٸ�, Up Casting�� �� ���¿����� ���� �ڷ����� Ȯ���� �� ����
	//3. �����Լ� ���̺��� ���ٸ� dynamic cast�� �̿��� �ٿ�ĳ������ �Ұ�����(������ ����), ��ĳ������ ��

	if (confirm == typeid(Base)) //type_info�� �񱳿�����(==, !=)�� �̿��� Ÿ�� ������ Ȯ�� ����
	{
		std::cout << confirm.name() << std::endl;
	}

	if (confirm == typeid(Derived))
	{
		std::cout << confirm.name() << std::endl;
	}

	size_t HASHCODE = confirm.hash_code(); //Ŭ���� ������ �ؽ��� ��ȯ
	std::string Name = confirm.name(); //����� ���� �� �ִ� �������� ���ڿ��� ��ȯ�մϴ�
	std::string Raw_Name = confirm.raw_name(); // ����ũ�μ���Ʈ ���� �Լ���׿�, ������ �����ϱ� ���� ���ڷ����� �� ������� ����ȴ�ϴ�
	bool result = typeid(Base).before(confirm); //�ڷ����� �ռ����� Ȯ��(���� ���� �Ǵ°� ����)
												//�ռ��ٴ� ������ c++���� ������ ������ �����̷���, �����Ϸ��� ���� �ٸ����� �ִٰ�....
												//���� �߿����� �����Ͱ���
	delete derivedPtr;
	delete BasePtr;
}