//문제 주소 : https://www.acmicpc.net/problem/2659

#include <iostream>
#include <vector>
#include <string>
#include <set>

int FindClockValue(const std::string& CrossNums)
{
	int ClockValue = INT32_MAX;
	for (int i = 0; i < 4; i++)
	{
		std::string temp;
		for (int j = i; j < i + 4; j++)
		{
			temp.push_back(CrossNums[j % 4]);
		}
		ClockValue = std::min(ClockValue, std::stoi(std::move(temp)));
	}

	return ClockValue;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::string ClockWiseNum;
	for (int i = 0; i < 4; i++)
	{	
		char temp;
		std::cin >> temp;
		ClockWiseNum.push_back(temp);
	}

	std::string CrossNum;
	CrossNum.resize(4);

	std::set<int> AllNums;

	for (int i = 1; i <= 9; i++)
	{
		CrossNum[0] = i + '0';
		for (int j = 1; j <= 9; j++)
		{
			CrossNum[1] = j + '0';
			for (int k = 1; k <= 9; k++)
			{
				CrossNum[2] = k + '0';
				for (int l = 1; l <= 9; l++)
				{
					CrossNum[3] = l + '0';
					AllNums.insert(FindClockValue(CrossNum));
				}
			}
		}
	}

	std::cout << std::distance(AllNums.begin(), AllNums.find(FindClockValue(ClockWiseNum))) + 1;

	return 0;
}