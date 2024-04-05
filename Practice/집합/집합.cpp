//https://www.acmicpc.net/problem/11723

#include <iostream>
#include <functional>
#include <map>

std::map<char, std::function<void(int)>> FuncTable;
int Group = 0;
int CheckResult = 0;
int CheckCount = 0;

void Add(int Value)
{
	Group |= 1 << (Value - 1);
}

void Remove(int Value)
{
	Group &= ~(1 << (Value - 1));
}

void Check(int Value)
{
	++CheckCount;
	if ((Group >> (Value - 1)) & 1)
	{
		CheckResult = CheckResult << 1;
		++CheckResult;
	}
	else
	{
		CheckResult = CheckResult << 1;
	}
}

void Toggle(int Value)
{
	if ((Group >> (Value - 1)) & 1)
	{
		Group &= ~(1 << (Value - 1));
	}
	else
	{
		Group |= 1 << (Value - 1);
	}
}

void All(int Value = -1)
{
	Group = 0b11111111111111111111;
}

void Empty(int Value = -1)
{
	Group = 0;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;

	FuncTable.insert(std::make_pair('d', Add));
	FuncTable.insert(std::make_pair('e', Remove));
	FuncTable.insert(std::make_pair('h', Check));
	FuncTable.insert(std::make_pair('o', Toggle));
	FuncTable.insert(std::make_pair('l', All));
	FuncTable.insert(std::make_pair('m', Empty));

	for (int i = 0; i < N; ++i)
	{
		std::string Cmd;
		int Value;
		std::cin >> Cmd;

		if (Cmd[1] != 'l' && Cmd[1] != 'm')
		{
			std::cin >> Value;
		}
		else
		{
			Value = -1;
		}

		FuncTable[Cmd[1]](Value);
	}

	for (int i = CheckCount; i > 0; --i)
	{
		std::cout << ((CheckResult >> (i - 1)) & 1) << "\n";
	}
}