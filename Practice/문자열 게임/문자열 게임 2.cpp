//문제 주소 : https://www.acmicpc.net/problem/20437

#include <iostream>
#include <vector>

std::vector<std::vector<int>> AsciiTable;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	AsciiTable.resize(26, std::vector<int>());

	int TestCase;

	std::cin >> TestCase;

	for (int k = 0; k < TestCase; k++)
	{
		for (int i = 0; i < 26; i++)
		{
			AsciiTable[i].clear();
		}

		std::string Data;
		std::cin >> Data;
		int PartCondition;
		std::cin >> PartCondition;
		int Min = INT32_MAX;
		int Max = INT32_MIN;

		for (int i = 0; i < Data.size(); i++)
		{
			int Index = Data[i] - 'a';
			AsciiTable[Index].push_back(i);

			if (AsciiTable[Index].size() >= PartCondition)
			{
				int LastIndex = AsciiTable[Index].back();
				int FirstIndex = *(AsciiTable[Index].end() - PartCondition);

				Min = std::min(Min, LastIndex - FirstIndex + 1);
				Max = std::max(Max, LastIndex - FirstIndex + 1);
			}
		}

		if (Min == INT32_MAX)
		{
			std::cout << -1 << '\n';
			continue;
		}
		std::cout << Min << " " << Max << '\n';
	}

	return 0;
}