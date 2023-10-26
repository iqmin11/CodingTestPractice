#include <iostream>
#include <vector>

int main()
{
	std::pair<int, int> Ex = std::pair<int, int>();
	std::vector<int> ExCoinType = std::vector<int>();
	
	std::cin >> Ex.first;
	std::cin >> Ex.second;

	ExCoinType.resize(Ex.first);

	for (size_t i = 0; i < ExCoinType.size(); i++)
	{
		std::cin >> ExCoinType[i];
	}

	auto StartIter = ExCoinType.rbegin();
	auto EndIter = ExCoinType.rend();
	int Answer = 0;

	for (; StartIter != EndIter; StartIter++)
	{
		if (*StartIter > Ex.second)
		{
			continue;
		}

		if (*StartIter == 0)
		{
			continue;
		}

		int Quotient = Ex.second / *StartIter;
		int Mod = Ex.second % *StartIter;

		Answer += Quotient;
		Ex.second = Mod;

		if (Ex.second == 0)
			break;
	}

	std::cout << Answer;

	return 0;
}

/*while (Ex.second >= *StartIter)
{
	Ex.second -= *StartIter;
	Answer++;
	if (Ex.second == 0)
		break;
}*/