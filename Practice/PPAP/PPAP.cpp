//문제 주소 : https://www.acmicpc.net/problem/16120

#include <iostream>
#include <stack>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::stack<char> PPAP;
	std::string str;
	std::cin >> str;

	int CheckCount = 0;

	for (size_t i = 0; i < str.size(); i++)
	{
		PPAP.push(str[i]);
		
	}

	

	return 0;
}