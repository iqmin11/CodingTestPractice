//https://www.acmicpc.net/problem/3273

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int N, X;

	std::cin >> N;

	std::vector<int> Arr;
	Arr.resize(N);
	for (size_t i = 0; i < N; i++)
	{
		std::cin >> Arr[i];
	}
	std::sort(Arr.begin(), Arr.end());

	std::cin >> X;

	int left = 0;
	int right = N - 1;
	int count = 0;

	while (left < right)
	{
		int CheckValue = Arr[left] + Arr[right];

		if (CheckValue == X)
		{
			count++;
			left++;
			right--;
		}
		else if (CheckValue < X)
		{
			left++;
		}
		else if (CheckValue > X)
		{
			right--;
		}
	}

	std::cout << count;

	return 0;
}