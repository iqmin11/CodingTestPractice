//https://www.acmicpc.net/problem/1515

#include <iostream>
#include <string>

int main()
{
	std::string Nums;
	std::cin >> Nums;

	int CurIndex = 0;
	int CurCheckNum = 0;

	for (CurCheckNum = 1; CurIndex < Nums.size(); CurCheckNum++)
	{
		std::string CheckNum = std::to_string(CurCheckNum);

		for (int i = 0; i < CheckNum.size(); i++)
		{
			if (Nums[CurIndex] == CheckNum[i])
			{
				CurIndex++;
			}
		}
	}

	std::cout << CurCheckNum - 1;
}