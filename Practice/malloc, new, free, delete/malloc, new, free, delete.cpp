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
	//C style 힙영역 메모리 할당 : malloc()
	//malloc은 힙영역의 memory를 특정 크기로 할당해주기만 함.
	//void*로 반환하기 때문에 사용할 자료형으로 캐스팅을 해줘야 함
	
	//해당 자료형 할당
	//malloc은 메모리를 할당하는것 만이 목적이기 때문에 할당과 동시에 초기화를 해 줄 수 없음
	Test* pMalloc;
	pMalloc = (Test*)(malloc(sizeof(Test)));
	pMalloc->mInt = 10;

	//배열 할당
	Test* pMallocArr;
	pMallocArr = (Test*)(malloc(sizeof(Test) * 4));
	for (int i = 0; i < 4; i++)
	{
		pMallocArr[i].mInt = i;
		std::cout << pMallocArr[i].mInt << std::endl;
	}

	//C style 힙영역 메모리 해제 : free()
	//free에서 해당 배열의 크기를 몰라도 되는 이유는 뭘까요?
	free(pMalloc);
	free(pMallocArr);

	//C++ style 힙영역 메모리 할당 : new
	//new는 자료형까지 정해주기 때문에 따로 캐스팅을 할 필요가 없음

	//해당 자료형 할당
	//생성자를 호출해주기 때문에 초기화도 가능하다
	Test* pNew = new Test(10);
	
	//배열 할당
	Test* pNewArr = new Test[4];

	//C++ style 힙영역 메모리 해제 : delete
	//소멸자를 호출해 줌
	delete pNew;

	//배열 해제
	delete[] pNewArr;

	_CrtDumpMemoryLeaks();

	return 0;
}