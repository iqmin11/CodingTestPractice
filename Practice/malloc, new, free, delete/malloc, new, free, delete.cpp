#include <iostream>
#include <crtdbg.h>

class Test
{
public:
	Test()
	{
		std::cout << "Constructor" << std::endl;
	}

	Test(int Init)
		: mInt(Init)
	{
		std::cout << "Constructor" << std::endl;
	}

	~Test()
	{
		std::cout << "Destructor" << std::endl;
	}

	int mInt = 0;
};

int main()
{
	//C style ������ �޸� �Ҵ� : malloc()
	//malloc�� �������� memory�� Ư�� ũ��� �Ҵ����ֱ⸸ ��.
	//void*�� ��ȯ�ϱ� ������ ����� �ڷ������� ĳ������ ����� ��
	
	//�ش� �ڷ��� �Ҵ�
	//malloc�� �޸𸮸� �Ҵ��ϴ°� ���� �����̱� ������ �Ҵ�� ���ÿ� �ʱ�ȭ�� �� �� �� ����
	Test* pMalloc;
	pMalloc = (Test*)(malloc(sizeof(Test)));
	pMalloc->mInt = 10;

	//�迭 �Ҵ�
	Test* pMallocArr;
	pMallocArr = (Test*)(malloc(sizeof(Test) * 4));
	for (int i = 0; i < 4; i++)
	{
		pMallocArr[i].mInt = i;
		std::cout << pMallocArr[i].mInt << std::endl;
	}

	//C style ������ �޸� ���� : free()
	//free���� �ش� �迭�� ũ�⸦ ���� �Ǵ� ������ �����?
	free(pMalloc);
	free(pMallocArr);

	//C++ style ������ �޸� �Ҵ� : new
	//new�� �ڷ������� �����ֱ� ������ ���� ĳ������ �� �ʿ䰡 ����

	//�ش� �ڷ��� �Ҵ�
	//�����ڸ� ȣ�����ֱ� ������ �ʱ�ȭ�� �����ϴ�
	Test* pNew = new Test(10);
	
	//�迭 �Ҵ�
	Test* pNewArr = new Test[4];

	//C++ style ������ �޸� ���� : delete
	//�Ҹ��ڸ� ȣ���� ��
	delete pNew;

	//�迭 ����
	delete[] pNewArr;

	_CrtDumpMemoryLeaks();

	return 0;
}