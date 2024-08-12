//문제 주소 : https://www.acmicpc.net/problem/1644

#include <iostream>
#include <vector>

std::vector<bool> IsPrime;
std::vector<int> PrimeNums;

int Max;

int main()
{
	std::cin >> Max;

	IsPrime.resize(Max + 1, true);
	IsPrime[0] = false;
	IsPrime[1] = false;
	for (int i = 2; i * i <= Max; i++)
	{
		if (IsPrime[i] == false)
		{
			continue;
		}

		for (int j = i + i; j <= Max; j += i)
		{
			IsPrime[j] = false;
		}
	}

	for (int i = 0; i <= Max; i++)
	{
		if (IsPrime[i])
		{
			PrimeNums.push_back(i);
		}
	}

	int Right = 0;
	int PartialAdd = 0;

	int Answer = 0;

	for (int Left = 0; Left < PrimeNums.size(); Left++)
	{
		while (PartialAdd < Max && Right < PrimeNums.size())
		{
			PartialAdd += PrimeNums[Right];
			Right++;
		}

		if (PartialAdd == Max)
		{
			Answer++;
		}

		PartialAdd -= PrimeNums[Left];
	}

	std::cout << Answer;

	return 0;
}