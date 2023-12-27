#include <typeinfo> //RTTI기능 중 typeid 연산자와 type_info 클래스를 사용하기 위한 헤더
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

	const std::type_info& confirm = typeid(*UpcastPtr); //typeid 연산자는 const type_info& 형태로 객체 정보를 반환
	//1. 가상함수 테이블 체크를 통해서 해당 객체의 형을 확인하기 때문에, 가상함수테이블이 없다면 정적인 클래스만 확인 가능(Base로 받았다면 Base로 반환)
	//2. 가상함수 테이블이 있다면, Up Casting을 한 상태에서도 실제 자료형을 확인할 수 있음
	//3. 가상함수 테이블이 없다면 dynamic cast를 이용한 다운캐스팅은 불가능함(컴파일 오류), 업캐스팅은 됨

	if (confirm == typeid(Base)) //type_info의 비교연산자(==, !=)를 이용해 타입 정보를 확인 가능
	{
		std::cout << confirm.name() << std::endl;
	}

	if (confirm == typeid(Derived))
	{
		std::cout << confirm.name() << std::endl;
	}

	size_t HASHCODE = confirm.hash_code(); //클래스 정보를 해쉬로 반환
	std::string Name = confirm.name(); //사람이 읽을 수 있는 형식으로 문자열을 반환합니다
	std::string Raw_Name = confirm.raw_name(); // 마이크로소프트 전용 함수라네요, 공간을 절약하기 위해 데코레이팅 된 방식으로 저장된답니다
	bool result = typeid(Base).before(confirm); //자료형이 앞서는지 확인(별로 몰라도 되는것 같음)
												//앞선다는 개념이 c++에서 정의한 사전식 기준이래요, 컴파일러에 따라서 다를수도 있다고....
												//별로 중요하지 않은것같음
	delete derivedPtr;
	delete BasePtr;
}