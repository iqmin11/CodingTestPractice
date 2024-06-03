
class A
{
public:
	void Test() const //해당 함수로 객체의 속성을 바꿀 수 없음
	{
		return;
	}

	int a = 0;
};

int main()
{
	int* Test = new int;
	const int* A = Test; //포인터가 가리키는 메모리 값을 상수화
	//*A = 8; //불가능
	A = nullptr; // 포인터가 가리키는 주소를 바꾸는 것은 가능
	
	int* const B = Test; //포인터가 가리키는 주소를 상수화
	*B = 8; // 포인터가 가리키는 메모리 값을 바꾸는 것은 가능
	//B = nullptr; //불가능

	const int* const C = Test; //주소와 값 둘다 상수화
	//*C = 8; //불가능
	//C = nullptr; //불가능

	return 0;
}