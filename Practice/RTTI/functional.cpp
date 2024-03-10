#include <iostream>
#include <functional>
#include <queue>

//전역함수
//1. 매개변수와 반환값이 둘다 없는 형태의 함수
void Function1() 
{
	std::cout << "매개변수와 반환값이 둘다 없는 형태의 함수" << std::endl;
}

//2. 반환값만 있는 형태의 함수
bool Function2()
{
	std::cout << "반환값만 있는 형태의 함수" << std::endl;
	return false;
}

//3. 매개변수만 있는 형태의 함수
void Function3(int a, int b)
{
	std::cout << "매개변수만 있는 형태의 함수" << std::endl;
}

//4. 매개변수와 반환값이 모두 있는 형태의 함수
bool Function4(int a, int b)
{
	std::cout << "매개변수와 반환값이 모두 있는 형태의 함수" << std::endl;
	return false;
}

//5. 멤버 함수
class TestClass
{
public:
	void TestClassFunction()
	{
		std::cout << "멤버 함수" << std::endl;
		a = 5;
		std::cout << a << std::endl;
	}

	static void StaticMemberFunc()
	{
		std::cout << "멤버 전역 함수" << std::endl;
	}

	int a = 10;
};


int main()
{
	//함수포인터와 functional의 차이를 기반으로 공부
	//함수포인터를 사용해보자
	
	//함수 포인터의 선언형태
	//반환형 (*변수명)(매개변수)
	void (*FuncPtr1)() = Function1;
	bool (*FuncPtr2)() = Function2;
	void (*FuncPtr3)(int, int) = Function3;
	bool (*FuncPtr4)(int, int) = Function4;

	//사용 예
	FuncPtr1();
	bool Boolean = FuncPtr2();
	std::cout << Boolean << std::endl;
	FuncPtr3(1, 3);
	Boolean = FuncPtr4(2, 4);
	std::cout << Boolean << std::endl;

	//멤버함수 테스트/////////////////////////////////
	TestClass MyInstance;
	void (TestClass::*FuncPtr5)() = &TestClass::TestClassFunction; //이렇게 쓰래.. 근데 이렇게 쓰면 어떤 객체가 쓸 함수일지 어떻게 알아?
	(MyInstance.*FuncPtr5)(); //이렇게 하면 된다네, 어떤 객체의 어떤 함수를 쓴다
	//그럼 뭐 자유 자제로 사용이 가능한건가? 굳이 functional을 써야 하는 이유가 뭘까 잘 모르겠네
	//일단 보이는 첫번째 문제 가독성이 안좋아.

	//전역함수 형태로는 당연히 사용 가능
	void (*FuncPtr6)() = &TestClass::StaticMemberFunc;
	FuncPtr6();

	//functional
	//장점 1. 함수의 시그니처와 상관없이 함수를 담을 수 있음
	//cf) 함수의 서명(시그니처)는 함수의 매개변수화 리턴형태를 말하는 것
	std::function<void()> FuncPtr7 = std::bind(&TestClass::TestClassFunction, MyInstance); //멤버함수
	FuncPtr7();
	std::function<bool()> FuncPtr8;
	FuncPtr7 = std::bind(Function1); //리턴, 매개변수 없는 함수
	FuncPtr7();
	FuncPtr7 = std::bind(Function2); //리턴만 있는 함수
	FuncPtr7(); //반환값이 없어졌네 사용은 가능한데
	FuncPtr8 = std::bind(Function2);
	Boolean = FuncPtr8(); //이렇게 쓰도록! 유연하게 담을수 있는 장점이 있지만 그만큼 실수할 여지도 있어보임
	int a = 0;
	
	std::function<void(int)> FuncPtr9 = std::bind(Function3, 20, std::placeholders::_1); //이렇게 써야하는군
	//placeholder는 넣을 인자를 빈 구멍으로 놔두는것
	FuncPtr9(2);//이런식의 사용이 가능하구나
	//정리를 하자면.. 함수포인터에 비해 굉장히굉장히 유연함
	//기존함수를 그대로 사용할 수도 있고.
	//기존함수를 활용해서 고정된 인자를 넣어버리는 파생 함수를 만들 수도 있고.
	//리턴값을 없앨수도 있고. 활용할수 있는 여지가 많음.
	
	//람다식과도 호환이 되기 때문에 유용함
	FuncPtr7 = std::bind([]()
		{
			std::cout << "람다 쌉가능" << std::endl;
		});
	FuncPtr7();
	//장점이 많네요 functional을 쓰는 이유를 알 것 같다.
}