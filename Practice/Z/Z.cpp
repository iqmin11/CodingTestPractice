//문제 주소 : https://www.acmicpc.net/problem/1074

#include <iostream>
#include <cmath>

int Recursive(std::pair<int, int> Pivot, int N)
{
	if (N == 1)
	{
		return 1;
	}

	std::pair<int, int> NextPivot = Pivot;
	int Half = N / 2;
	int Result = 0;

	if (Pivot.first < Half)
	{
		if (Pivot.second < Half)
		{
			Result = Recursive(NextPivot, Half);
		}
		else
		{
			NextPivot.second -= Half;
			Result = Recursive(NextPivot, Half);
			Result += Half * Half * 2;
		}
	}
	else
	{
		if (Pivot.second < Half)
		{
			NextPivot.first -= Half;
			Result = Recursive(NextPivot, Half);
			Result += Half * Half;
		}
		else
		{
			NextPivot.first -= Half;
			NextPivot.second -= Half;
			Result = Recursive(NextPivot, Half);
			Result += Half * Half * 3;
		}
	}

	return Result;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, r, c;

	std::cin >> N >> r >> c;

	int Pow = std::pow(2, N);

	int Answer = Recursive(std::make_pair(c,r), Pow);
	std::cout << Answer - 1;

	return 0;
}