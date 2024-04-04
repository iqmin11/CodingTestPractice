//https://www.acmicpc.net/problem/1158
#include <iostream>
#include <list>
#include <string>

std::list<int> Data;

std::list<int>::iterator MoveIter(std::list<int>::iterator CurIter, int K)
{
	for (int i = 0; i < K - 1; i++)
	{
		if (CurIter == Data.end())
		{
			CurIter = Data.begin();
		}
		++CurIter;
	}

	if (CurIter == Data.end())
	{
		CurIter = Data.begin();
	}

	return CurIter;
}


int main()
{
	int N, K;

	std::cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		Data.push_back(i + 1);
	}

	auto CurIter = Data.begin();
	std::string Answer;
	Answer.reserve(3 * N);

	while (!Data.empty())
	{
		auto EraseIter = MoveIter(CurIter, K);
		Answer += " " + std::to_string(*EraseIter) + ",";
		CurIter = Data.erase(EraseIter);
	}

	Answer.front() = '<';
	Answer.back() = '>';

	std::cout << Answer;
}