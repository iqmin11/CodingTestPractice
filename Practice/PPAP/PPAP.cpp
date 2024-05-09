//문제 주소 : https://www.acmicpc.net/problem/16120

#include <iostream>
#include <stack>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::string Str;
	std::cin >> Str;

	std::stack<char> St;
	St.push	(Str.front());

	for (size_t i = 1; i < Str.size(); i++)
	{
		if (St.size() <= 2)
		{
			St.push(Str[i]);
			continue;
		}

		if (St.top() == 'A' && Str[i] == 'P')
		{
			St.pop();
			char PrevChar = St.top();
			
			St.pop();
			char PrevPrevChar = St.top();

			if (PrevChar == PrevPrevChar && PrevChar == 'P')
			{
				continue;
			}

			St.push('P');
			St.push('A');
		}

		St.push(Str[i]);
	}

	if (St.size() == 1 && St.top() == 'P')
	{
		std::cout << "PPAP";
		return 0;
	}
	
	std::cout << "NP";
	return 0;
}