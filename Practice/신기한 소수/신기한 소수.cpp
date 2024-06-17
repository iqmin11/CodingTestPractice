//문제 주소 : https://www.acmicpc.net/problem/2023

#include <iostream>
#include <string>
#include <cmath>

int Length;
std::string Path;

bool CheckPrime(int Value)
{
	if (Value == 1)
	{
		return false;
	}

	int CheckSize = std::sqrt(Value);

	for (int i = 2; i <= CheckSize; i++)
	{
		if (Value % i == 0)
		{
			return false;
		}
	}

	return true;
}

void BT()
{
	if (Path.empty())
	{
		for (size_t i = 0; i < 10; i++)
		{
			if (Path.empty() && i == 0)
			{
				continue;
			}

			Path.push_back(i + '0');
			BT();
			Path.pop_back();
		}
		return;
	}

	int CurNum = std::stoi(Path);

	if (!CheckPrime(CurNum))
	{
		return;
	}

	if (Path.size() >= Length)
	{
		std::cout << Path << std::endl;
		return;
	}


	for (size_t i = 0; i < 10; i++)
	{
		Path.push_back(i + '0');
		BT();
		Path.pop_back();
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> Length;
	Path.reserve(Length);
	BT();

	return 0;
}