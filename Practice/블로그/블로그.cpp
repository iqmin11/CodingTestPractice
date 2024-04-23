//https://www.acmicpc.net/problem/21921

#include <iostream>
#include <vector>

int main()
{
	int N, X;

	std::cin >> N >> X;

	std::vector<int> Data;
	Data.resize(N);

	for (int i = 0; i < N; i++)
	{
		std::cin >> Data[i];
	}

	int right = 0;
	int PartAdd = 0;
	int Max = INT32_MIN;
	int Count = 0;

	for (int left = 0; left < N; left++)
	{
		while (right - left != X && right < N)
		{
			PartAdd += Data[right];
			right++;
		}

		if (Max < PartAdd)
		{
			Max = PartAdd;
			Count = 0;
		}

		if (Max == PartAdd)
		{
			Count++;
		}

		PartAdd -= Data[left];
	}

	if (Max == 0)
	{
		std::cout << "SAD";
	}
	else
	{
		std::cout << Max << '\n';
		std::cout << Count << '\n';
	}

}
