//문제 주소 : https://www.acmicpc.net/problem/2011

#include <iostream>
#include <string>

int AsciiTable[27];
const int Mod = 1000000;

//맞긴한데... 들어오는 숫자가 너무 커서 (10^5000) 재귀로 풀면 별로임
int Recursive(const std::string& Value)
{
	if (Value.size() <= 2)
	{
		int CurIntValue = std::stoi(Value);
		if (CurIntValue <= 26)
		{
			return AsciiTable[CurIntValue];
		}
	}

	int FirstTwoDigitValue = std::stoi(Value.substr(0,2));
	std::string LeftValue = Value.substr(1, Value.size());
	std::string RightValue = "0";
	if (FirstTwoDigitValue <= 26)
	{
		RightValue = Value.substr(2, Value.size());
	}

	return Recursive(LeftValue) + Recursive(RightValue);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::string N;
	std::cin >> N;

	for (int i = 1; i <= 10; i++)
	{
		AsciiTable[i] = 1;
	}

	for (int i = 11; i <= 26; i++)
	{
		AsciiTable[i] = 2;
	}
	
	std::cout << Recursive(N);
	return 0;
}