#include <iostream>
#include <crtdbg.h>

//얕은 복사 시 무조건 문제가 되는 구조의 클래스
//얕은 복사는 클래스의 복사 생성시, 복사 대상이 되는 인스턴스의 데이터를 그대로 복사하여 생성합니다.
//깊은 복사는 클래스의 복사 생성시, 새로운 공간에 메모리공간을 확보하고, 그곳에 데이터를 복사합니다.

//벡터의 복사생성자가 깊은복사로 구현되어있는 이유
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

	//얕은 복사
	/*MyVector(const MyVector& Other)
	{
		Arr = Other.Arr;
		std::cout << "My Arr Address : " << reinterpret_cast<__int64>(Arr) << std::endl;
	}*/

	//깊은 복사
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
		MyVector B(A); //B는 MyVector의 복사생성자 호출 -> 얕은 복사
		//A소멸자 호출 -> Arr메모리 해제
		//B소멸자 호출 -> Arr메모리 해제 -> 이미 해제된 메모리 -> 어썰트
	}
	_CrtDumpMemoryLeaks();
	return 0;
}