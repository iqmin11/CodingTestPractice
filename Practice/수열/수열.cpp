//https://www.acmicpc.net/problem/2559

#include <iostream>
#include <vector>

int main()
{
	int N, K;
	std::cin >> N >> K;

	std::vector<int> Arr;
	Arr.resize(N);
	for (size_t i = 0; i < N; i++)
	{
		std::cin >> Arr[i];
	}

	int right = 0;
	int PartAdd = 0;
	int MaxValue = INT32_MIN;

	for (size_t left = 0; left < N; left++)
	{
		while (right - left + 1 <= K && right < N)
		{
			PartAdd += Arr[right];

			if (right - left + 1 == K)
			{
				MaxValue = std::max(MaxValue, PartAdd);
			}

			right++;
		}

		PartAdd -= Arr[left];
	}

	std::cout << MaxValue;

	return 0;
}