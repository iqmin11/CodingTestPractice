#include <iostream>
#include <string_view>

std::string StrTest(std::string_view _value)
{
	return _value.data();
}

std::string StrWrong(const std::string& _value)
{
	return _value.data();
}

int main()
{
	std::string_view Strview = "asdasdasdasdsa"; //어떤 형태의 문자열 데이터를 받아도, 데이터 그자체를 갖고 있는게 아니라 입력한 곳을 포인터로 가리킬뿐
	
	int strviewSize = sizeof(Strview); //크기 16byte의 자료형
	//8byte는 const char*(문자열 포인터, const이기 때문에 문자열 리터럴도 받을 수 있는거), 8byte는 unsigned __int64 (문자열의 size 저장)

	std::string Str = Strview.data(); //이런 경우에는 당연하게 str로 생성하겠죠

	char cstyle[10] = "what"; //c스타일 문자열
	
	//스트링 뷰를 사용하는이유
	Str = StrTest("asdas"); //문자열 리터럴
	Str = StrTest(cstyle); //c스타일 문자열(char*)
	Str = StrTest(Str); //std::stirng
	//어떤 형태의 문자열을 인자로 받아도 동적할당이 일어나지 않음

	//반면 string&를 사용하는 경우
	Str = StrWrong(Str); //복사생성 일어나지 않죠 당연히 여긴
	Str = StrWrong("asdas"); //문자열 리터럴 : 동적할당 일어남(std::string("asdas"))
	Str = StrWrong(cstyle); //c스타일 문자열 : 동적할당 일어남(std::string(cstyle))

	//이런 이유로 string_view를 씁니다.
}