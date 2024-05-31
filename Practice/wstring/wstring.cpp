#include <iostream>
#include <string>
#include <sstream>

int main()
{
	//cin cout에 한국어가 깨지지 않게 하기 위한 조치
	std::wcin.imbue(std::locale("korean"));
	std::wcout.imbue(std::locale("korean"));

	//한국어를 사용하기위한 자료형 wstring, 기본적으로 wchar_t를 씀
	std::wstring WStr;

	//wstr의 stringstream, 똑같이 사용 가능
	std::wstringstream WSS; 

	//wstr의  cin, cout
	std::wcin;
	std::wcout;

	return 0;
}