#include <iostream>
#include <crtdbg.h>

//���� ���� �� ������ ������ �Ǵ� ������ Ŭ����
//���� ����� Ŭ������ ���� ������, ���� ����� �Ǵ� �ν��Ͻ��� �����͸� �״�� �����Ͽ� �����մϴ�.
//���� ����� Ŭ������ ���� ������, ���ο� ������ �޸𸮰����� Ȯ���ϰ�, �װ��� �����͸� �����մϴ�.

//������ ��������ڰ� ��������� �����Ǿ��ִ� ����
class MyVector
{
public:
	MyVector()
		: Arr(new int[10])
	{
		std::cout << "My Arr Address : " << reinterpret_cast<__int64>(Arr) << std::endl;
		for (size_t i = 0; i < 10; i++)
		{
			Arr[i] = i + 1;
		}
	}

	//���� ����
	/*MyVector(const MyVector& Other)
	{
		Arr = Other.Arr;
		std::cout << "My Arr Address : " << reinterpret_cast<__int64>(Arr) << std::endl;
	}*/

	//���� ����
	MyVector(const MyVector& Other)
	{
		Arr = new int[10];
		for (size_t i = 0; i < 10; i++)
		{
			Arr[i] = Other.Arr[i];
		}
		std::cout << "My Arr Address : " << reinterpret_cast<__int64>(Arr) << std::endl;
	}

	~MyVector()
	{
		std::cout << "Delete Address : " << reinterpret_cast<__int64>(Arr) << std::endl;
		delete Arr;
	}

	int* Arr;
};

int main()
{
	{
		MyVector A;
		MyVector B(A); //B�� MyVector�� ��������� ȣ�� -> ���� ����
		//A�Ҹ��� ȣ�� -> Arr�޸� ����
		//B�Ҹ��� ȣ�� -> Arr�޸� ���� -> �̹� ������ �޸� -> ���Ʈ
	}
	_CrtDumpMemoryLeaks();
	return 0;
}