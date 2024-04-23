//https://www.acmicpc.net/problem/12904

#include <iostream>
#include <deque>

std::deque<char> Start;
std::deque<char> RStart;
std::deque<char> Target;

bool IsReverse = false;

void Operate1() // �ڿ� A�� ����
{
	if (IsReverse)
	{
		Target.pop_front();
	}
	else
	{
		Target.pop_back();
	}
}

void Operate2() // �ڿ� B�� ���� ������
{
	if (IsReverse)
	{
		Target.pop_front();
	}
	else
	{
		Target.pop_back();
	}

	IsReverse = !IsReverse;
}

int main()
{
	std::string S, T;
	std::cin >> S >> T;


	for (size_t i = 0; i < S.size(); i++)
	{
		Start.push_back(S[i]);
		RStart.push_back(S[S.size() - (i + 1)]);
	}

	for (size_t i = 0; i < T.size(); i++)
	{
		Target.push_back(T[i]);
	}

	while (Start.size() != Target.size())
	{
		char TargetBack;

		if (IsReverse)
		{
			TargetBack = Target.front();
		}
		else
		{
			TargetBack = Target.back();
		}

		if (TargetBack == 'A')
		{
			Operate1();
		}
		else if(TargetBack == 'B')
		{
			Operate2();
		}
	}

	if (IsReverse)
	{
		Start = RStart;
	}

	if (Start == Target)
	{
		std::cout << 1;
	}
	else
	{
		std::cout << 0;
	}
	
	return 0;
}

