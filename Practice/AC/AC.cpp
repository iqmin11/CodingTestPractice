//https://www.acmicpc.net/problem/5430

#include <iostream>
#include <list>
#include <queue>
#include <sstream>

std::deque<int> dq;
std::vector<std::string> Result;

std::string Func(const std::string& Command)
{
	bool CurState = false; //false : ¾Õ»©±â, true : µÚ»©±â

	std::deque<char> Cmd;
	for (size_t i = 0; i < Command.size(); i++)
	{
		char PushCmd = Command[i];
		if (PushCmd == 'R')
		{
			if (Cmd.empty() || Cmd.back() != 'R')
			{
				Cmd.push_back(PushCmd);
			}
			else if (Cmd.back() == 'R')
			{
				Cmd.pop_back();
			}
		}
		else
		{
			Cmd.push_back(PushCmd);
		}
	}

	while (!Cmd.empty())
	{
		char CurCmd = Cmd.front();
		Cmd.pop_front();

		if (CurCmd == 'R')
		{
			CurState = !CurState;
		}
		else
		{
			if (!dq.empty())
			{
				if (CurState)
				{
					dq.pop_back();
				}
				else
				{
					dq.pop_front();
				}
			}
			else
			{
				return "error";
			}
		}
	}

	std::string PrintStr = "[";
	while (!dq.empty())
	{
		int PrintNum = -1;
		if (CurState)
		{
			PrintNum = dq.back();
			dq.pop_back();
		}
		else
		{
			PrintNum = dq.front();
			dq.pop_front();
		}

		PrintStr += std::to_string(PrintNum) + ",";
	}

	if (PrintStr.back() == ',')
	{
		PrintStr.back() = ']';
	}
	else
	{
		PrintStr += "]";
	}

	return PrintStr;
}

int main()
{
	int T;
	std::cin >> T;
	std::vector<std::string> Result;
	Result.reserve(T);

	for (size_t k = 0; k < T; k++)
	{
		std::string Cmd;
		std::cin >> Cmd;
		int n;
		std::cin >> n;

		std::string Arr;
		std::cin >> Arr;

		for (size_t i = 0; i < Arr.size(); i++)
		{
			if (Arr[i] < '0' || '9' < Arr[i])
			{
				Arr[i] = ' ';
			}
		}

		std::stringstream Temp(Arr);

		for (size_t i = 0; i < n; i++)
		{
			int PushNum;
			Temp >> PushNum;
			dq.push_back(PushNum);
		}

		Result.push_back(Func(Cmd));
	}

	for (size_t i = 0; i < Result.size(); i++)
	{
		std::cout << Result[i] << std::endl;
	}
}