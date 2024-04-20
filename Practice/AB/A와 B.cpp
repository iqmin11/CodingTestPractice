//https://www.acmicpc.net/problem/12904

#include <iostream>
#include <deque>
#include <vector>

std::string S, T;
std::deque<char> Target;
std::deque<char> RTarget;
bool IsReverse = false;
std::vector<int> IsVisit; // IsVisit[0] = A를 사용할 수 있는 갯수 // IsVisit[1] = B를 사용할 수 있는 갯수 

bool IsSame(const std::deque<char>& CurStr)
{
	if (!IsReverse)
	{
		return CurStr == Target;
	}
	else
	{
		return CurStr == RTarget;
	}

	return true;
}

bool Result = false;

void BT(std::deque<char>& CurStr)
{
	if (CurStr.size() == Target.size() || Result)
	{
		if (Result)
		{
			return;
		}

		if (IsSame(CurStr))
		{
			Result = true;
			return;
		}
		return;
	}

	if (IsVisit[0] > 0)
	{
		--IsVisit[0];
		if (IsReverse)
		{
			CurStr.push_front('A');
		}
		else
		{
			CurStr.push_back('A');
		}
		BT(CurStr);
		if (IsReverse)
		{
			CurStr.pop_front();
		}
		else
		{
			CurStr.pop_back();
		}
		++IsVisit[0];
	}

	if (IsVisit[1] > 0)
	{
		--IsVisit[1];
		IsReverse = !IsReverse;

		if (IsReverse)
		{
			CurStr.push_front('B');
		}
		else
		{
			CurStr.push_back('B');
		}

		BT(CurStr);

		if (IsReverse)
		{
			CurStr.pop_front();
		}
		else
		{
			CurStr.pop_back();
		}

		IsReverse = !IsReverse;
		++IsVisit[1];
	}
}

int main()
{
	std::cin >> S >> T;

	IsVisit.resize(2, 0);
	std::deque<char> Start;
	for (int i = 0; i < S.size(); ++i)
	{
		--IsVisit[S[i] - 'A'];
		Start.push_back(S[i]);
	}

	for (int i = 0; i < T.size(); ++i)
	{
		++IsVisit[T[i] - 'A'];
		Target.push_back(T[i]);
		RTarget.push_front(T[i]);
	}

	if (IsVisit[0] < 0 || IsVisit[1] < 0)
	{
		std::cout << false;
		return 0;
	}

	BT(Start);

	std::cout << Result;

	return 0;
}

