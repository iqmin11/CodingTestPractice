//문제 주소 : https://www.acmicpc.net/problem/19942

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

int N;
std::vector<int> StdInfo; //영양소 기준
std::vector<std::vector<int>> Ingrediants; //재료 정보

std::deque<int> Select;
std::vector<int> Sum;

void Add(const std::vector<int>& Ingrediant)
{
	for (size_t i = 0; i < Ingrediant.size(); i++)
	{
		Sum[i] += Ingrediant[i];
	}
}

void Sub(const std::vector<int>& Ingrediant)
{
	for (size_t i = 0; i < Ingrediant.size(); i++)
	{
		Sum[i] -= Ingrediant[i];
	}
}

bool Check()
{
	for (size_t i = 0; i < Sum.size() - 1; i++)
	{
		if (Sum[i] < StdInfo[i])
		{
			return false;
		}
	}

	return true;
}

int Answer = INT32_MAX;
std::deque<int> MinSelect;

void BT(int SelectIndex)
{
	if (Select.size() > N)
	{
		return;
	}

	if (Check())
	{
		if (Answer > Sum[4])
		{
			Answer = Sum[4];
			MinSelect = Select;
		}

		return;
	}

	for (int i = SelectIndex; i < N; i++)
	{
		Select.push_back(i);
		Add(Ingrediants[i]);

		BT(i + 1);

		Sub(Ingrediants[i]);
		Select.pop_back();
	}
}

int main()
{
	std::cin >> N;

	StdInfo.resize(4);

	for (size_t i = 0; i < 4; i++)
	{
		std::cin >> StdInfo[i];
	}

	Ingrediants.resize(N);
	for (size_t y = 0; y < N; y++)
	{
		Ingrediants[y].resize(5);
		for (size_t x = 0; x < 5; x++)
		{
			std::cin >> Ingrediants[y][x];
		}
	}

	Sum.resize(5);

	BT(0);

	if (Answer == INT32_MAX)
	{
		std::cout << -1;
		return 0;
	}

	std::cout << Answer << std::endl;

	for (size_t i = 0; i < MinSelect.size(); i++)
	{
		std::cout << MinSelect[i] + 1 << " ";
	}

	return 0;
}