//https://www.acmicpc.net/problem/1927

#include <iostream>
#include <queue>

std::priority_queue<long long, std::vector<long long>, std::greater<long long>> Data;
std::vector<long long> Answer;

void Operation1(long long _Num)
{
	Data.push(_Num);
}

void Operation2()
{
	if (!Data.empty())
	{
		Answer.push_back(Data.top());
		Data.pop();
	}
	else
	{
		Answer.push_back(0);
	}
}

int main()
{
	int N;

	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		long long Cmd;
		std::cin >> Cmd;

		if (Cmd == 0)
		{
			Operation2();
		}
		else
		{
			Operation1(Cmd);
		}
	}

	for (int i = 0; i < Answer.size(); i++)
	{
		std::cout << Answer[i] << '\n';
	}
}