//https://www.acmicpc.net/problem/1701

#include <iostream>
#include <vector>

int GetPiArr(const std::string& Str)
{
	int Lenth = static_cast<int>(Str.size());
	int j = 0;
	std::vector<int> PiArr(Lenth, 0);

	int Max = 0;

	for (int i = 1; i < Lenth; i++)
	{
		while (j > 0 && Str[i] != Str[j])
		{
			j = PiArr[j - 1];
		}

		if (Str[i] == Str[j])
		{
			PiArr[i] = ++j;
			Max = std::max(Max, PiArr[i]);
		}
	}

	return Max;
}

int main()
{
	std::string Str;
	std::cin >> Str;
	std::cout << GetPiArr(Str);

	return 0;
}