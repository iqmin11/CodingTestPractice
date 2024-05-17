//문제 주소 : https://www.acmicpc.net/problem/5397

#include <iostream>
#include <list>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int TestCase;
	
	std::cin >> TestCase;

	//문자열 입력은 리스트로, 이동과 삽입 삭제 등은 이터레이터로 처리하면 될 듯 하다
	while (TestCase-- != 0)
	{
		std::string Cmd;
		std::cin >> Cmd;

		std::list<char> InputStr;
		auto CursorIter = InputStr.end();

		for (int i = 0; i < Cmd.size(); i++)
		{
			if (Cmd[i] == '<')
			{
				if (CursorIter == InputStr.begin())
				{
					continue;
				}

				--CursorIter;
			}
			else if (Cmd[i] == '>')
			{
				if (CursorIter == InputStr.end())
				{
					continue;
				}

				++CursorIter;
			}
			else if (Cmd[i] == '-')
			{
				if (CursorIter != InputStr.begin())
				{
					--CursorIter;
				}
				else
				{
					continue;
				}

				if (CursorIter == InputStr.end())
				{
					continue;
				}

				CursorIter = InputStr.erase(CursorIter);
			}
			else
			{
				InputStr.insert(CursorIter, Cmd[i]);
			}
		}

		for (auto Char : InputStr)
		{
			std::cout << Char;
		}
		std::cout << '\n';
	}

	return 0;
}