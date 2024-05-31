//문제 주소 : https://www.biko.kr/problem/1694

#include <iostream>
#include <sstream>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	//cin cout에 한국어가 깨지지 않게 하기 위한 조치
	std::wcin.imbue(std::locale("korean"));
	std::wcout.imbue(std::locale("korean"));

	//단순히 cin >> 연산자로 받을 시, \n가 남더라구요, 그래서 아얘 getline으로 받아버림
	//한국어를 사용하기위한 자료형 wstring, 기본적으로 wchar_t를 씀
	std::wstring NStr;
	std::getline(std::wcin, NStr);

	int N = std::stoi(NStr); // N으로 변환

	std::vector<std::wstring> Answer;

	Answer.resize(N);

	for (int i = 0; i < N; i++)
	{
		std::wstring Str;
		
		std::getline(std::wcin, Str);

		std::wstringstream Buffer(Str);

		std::wstring temp;
		
		while (Buffer >> temp)
		{
			Answer[i].push_back(temp[0]);
		}
	}

	std::wcout << std::endl;

	for (auto& i : Answer)
	{
		std::wcout << i << std::endl;
	}
	
	return 0;
}