//https://www.acmicpc.net/problem/1783

#include <iostream>

int main()
{
	int N, M;
	std::cin >> N >> M;

	int MoveCount = 0;

	if (N <= 1)
	{
		MoveCount = 0;
	}
	else if (N == 2)
	{
		if (M <= 7)
		{
			// 1 2 3 4 5 6 7 
			// 0 0 1 1 2 2 3
			MoveCount = (M - 1) / 2;
		}
		else
		{
			MoveCount = 3;
		}
	}
	else
	{
		if (M <= 4)
		{
			//1 2 3 4 5 6
			//0 1 2 3 3 3
			MoveCount = M - 1;
		}
		else if (M <= 6)
		{
			MoveCount = 3;
		}
		else
		{
			//7 8 9 10 
			//4 5 6 7 
			MoveCount = M - 3;
		}
	}

	std::cout << MoveCount + 1;
}