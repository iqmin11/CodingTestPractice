#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int N;
	std::cin >> N;

	std::vector<int> Arr;
	Arr.resize(N);

	for (int i = 0; i < N; i++)
	{
		std::cin >> Arr[i];
	}

	std::sort(Arr.begin(), Arr.end(), [](int _Left, int _Right)
		{
			return abs(_Left) < abs(_Right);
		});

	int DifferMin = INT32_MAX;
	std::pair<int, int> Answer;

	for (int i = 0; i < N-1; i++)
	{
		int PrevMin = DifferMin;
		DifferMin = std::min(DifferMin, abs(Arr[i] + Arr[i + 1]));

		if (DifferMin != PrevMin)
		{
			if (Arr[i] < Arr[i + 1])
			{
				Answer = std::make_pair(Arr[i], Arr[i + 1]);
			}
			else
			{
				Answer = std::make_pair(Arr[i + 1], Arr[i]);
			}
		}

		if (DifferMin == 0)
		{
			break;
		}
	}

	std::cout << Answer.first << " " << Answer.second;

	return 0;
}