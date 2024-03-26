//https://www.acmicpc.net/problem/1072

#include <iostream>

int main()
{
	long long X, Y;
	long long Z;
	std::cin >> X >> Y;

	Z = (Y * 100) / X;

	//Z를 변하게하는 수 중 가장 작은 A

	long long left = 0;
	long long right = 1000000000;
	long long mid = 0;
	long long MinValue = 1000000001;

	while (left <= right)
	{
		mid = (left + right) / 2;
		long long NextZ = ((Y + mid) * 100) / (X + mid);

		if (NextZ > Z)
		{
			right = mid - 1;
			MinValue = std::min(MinValue, mid);
		}
		else 
		{
			left = mid + 1;
		}
	}

	if (MinValue == 1000000001)
	{
		MinValue = -1;
	}

	std::cout << MinValue;

}