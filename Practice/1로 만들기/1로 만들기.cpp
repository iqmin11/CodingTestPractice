#include <iostream>
#include <set>
#include <vector>

//bottom-up
//1에서 시작

//계산방식은 세가지: 3으로 곱한다, 2로 곱한다, 1을 더한다

//상향식
int Bottom_Up0(int _X)
{
	if (_X == 1 || _X == 0)
	{
		return 0;
	}

	std::vector<std::set<int>> SaveResult;
	SaveResult.resize(100000);
	SaveResult[0].insert(1);
	int y = 0;

	while (true)
	{
		for (auto& i : SaveResult[y])
		{
			if (i * 3 == _X || i * 2 == _X || i + 1 == _X)
			{
				return y + 1;
			}
			
			if (SaveResult[y].find(i * 3) == SaveResult[y].end())
			{
				SaveResult[y + 1].insert(i * 3);
			}

			if (SaveResult[y].find(i * 2) == SaveResult[y].end())
			{
				SaveResult[y + 1].insert(i * 2);
			}
			
			if (SaveResult[y].find(i + 1) == SaveResult[y].end())
			{
				SaveResult[y + 1].insert(i + 1);
			}
		}

		y++;
	}

	return 0;
}

int Bottom_Up1(int _X)
{
	if (_X == 1 || _X == 0)
	{
		return 0;
	}

	std::vector<std::set<int>> SaveResult;
	SaveResult.resize(100);
	SaveResult[0].insert(_X);
	int y = 0;

	while (true)
	{
		for (auto& i : SaveResult[y])
		{
			if ((i % 3 == 0 && i / 3 == 1) || (i % 2 == 0 && i / 2 == 1) || i - 1 == 1)
			{
				return y + 1;
			}

			if (SaveResult[y].find(i / 3) == SaveResult[y].end() && i % 3 == 0)
			{
				SaveResult[y + 1].insert(i / 3);
			}

			if (SaveResult[y].find(i / 2) == SaveResult[y].end() && i % 2 == 0)
			{
				SaveResult[y + 1].insert(i / 2);
			}

			if (SaveResult[y].find(i - 1) == SaveResult[y].end())
			{
				SaveResult[y + 1].insert(i - 1);
			}
		}

		y++;
	}

	return 0;
}

int DP[1000001];

int Bottom_Up2(int _X)
{
	DP[1] = 0;

	for (size_t i = 2; i <= _X; i++)
	{
		DP[i] = DP[i - 1] + 1;

		if (i % 3 == 0)
		{
			DP[i] = std::min(DP[i], DP[i / 3] + 1);
		}

		if (i % 2 == 0)
		{
			DP[i] = std::min(DP[i], DP[i / 2] + 1);
		}
	}

	return DP[_X];
}

int main()
{
	int X = 0;
	std::cin >> X;
	std::cout << Bottom_Up0(X) << '\n';
	std::cout << Bottom_Up1(X) << '\n';
	std::cout << Bottom_Up2(X) << '\n';
	return 0;
}