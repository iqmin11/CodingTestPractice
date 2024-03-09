//https://www.acmicpc.net/problem/5430

#include <iostream>
#include <list>
#include <queue>
#include <sstream>

void R(std::list<int>& _List)
{
	_List.reverse();
}

bool D(std::list<int>& _List)
{
	if (_List.empty())
	{
		return false;
	}

	_List.pop_front();
	return true;
}

std::string Command(const std::string& _Cmd, std::list<int>& _List)
{
	for (size_t i = 0; i < _Cmd.size(); i++)
	{
		if (_Cmd[i] == 'R')
		{
			R(_List);
		}
		else if (_Cmd[i] == 'D')
		{
			if (!D(_List))
			{
				return "error";
			}
		}
	}
	
	std::string Answer;
	auto BackIter = _List.end();
	if (!_List.empty())
	{
		--BackIter;
	}

	Answer += '[';
	for (auto CurIter = _List.begin(); CurIter != _List.end(); ++CurIter)
	{
		if (CurIter == BackIter)
		{
			Answer += (*CurIter + '0');
			
		}
		else
		{
			Answer += (*CurIter + '0');
			Answer += ',';
		}
	}
	Answer += ']';

	return Answer;
}

int main()
{
	int T;
	std::cin >> T;
	std::vector<std::string> Answers;

	for (size_t k = 0; k < T; k++)
	{
		char Input;
		std::string Cmd;
		std::cin >> Input;
		while (Input == 'R' || Input == 'D')
		{
			Cmd += Input;
			std::cin >> Input;
		}
		int N = Input - '0';
		std::cin >> Input;

		std::list<int> List;
		int CurNum = 0;

		while (true)
		{
			if (Input == ',')
			{
				List.push_back(CurNum);
				std::cin >> Input;
				CurNum = 0;
				continue;
			}

			if (Input == ']')
			{
				List.push_back(CurNum);
				std::cin >> Input;
				CurNum = 0;
				break;
			}

			if (Input >= '0' && Input <= '9')
			{
				CurNum += CurNum * 10 + (Input - '0');
			}

			std::cin >> Input;
		}

		Answers.push_back(Command(Cmd, List));
	}

	for (size_t i = 0; i < T; i++)
	{
		std::cout << Answers[i] << '\n';
	}
}