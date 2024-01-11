#include <iostream>
#include <vector>
#include <algorithm>

uint32_t N, Max;
std::vector<uint32_t> EachBudget;

uint32_t CalBudget(uint32_t _Mid)
{
	uint32_t result = 0;
	for (size_t i = 0; i < EachBudget.size(); i++)
	{
		result += std::min(EachBudget[i], _Mid);
	}
	return result;
}

int main()
{
	std::cin >> N;
	EachBudget.resize(N);
	for (size_t i = 0; i < N; i++)
	{
		std::cin >> EachBudget[i];
	}
	std::sort(EachBudget.begin(), EachBudget.end());

	std::cin >> Max;

	uint32_t Left = 0;
	uint32_t Right = EachBudget.back();
	uint32_t Mid = 0;
	uint32_t MaxBudget = 0;

	while (Left <= Right)
	{
		Mid = (Left + Right) / 2;
		uint32_t CheckBudget = CalBudget(Mid);

		if (CheckBudget > Max) //ÁÙ¿©¾ßµÊ
		{
			Right = Mid - 1;
		}

		if (CheckBudget < Max) //´Ã·Á¾ßµÊ
		{
			MaxBudget = std::max(MaxBudget, Mid); //ÃÖ´ë°ª °»½Å
			Left = Mid + 1;
		}

		if (CheckBudget == Max) //ÀÌ°Ç Å»Ãâ
		{
			MaxBudget = std::max(MaxBudget, Mid);
			break;
		}
	}

	std::cout << MaxBudget;

	return 0;
}