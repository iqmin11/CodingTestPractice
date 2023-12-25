#include <iostream>
#include <vector>

int main()
{
	int N, M;
	std::cin >> N >> M;

	std::vector<int> Data;
	Data.reserve(N);

	for (size_t i = 0; i < N; i++)
	{
		int input;
		std::cin >> input;
		Data.emplace_back(input);
	}

	int right = 0;
	int PartSum = 0;
	int Count = 0;

	for (size_t left = 0; left < N; left++)
	{
		while (PartSum < M && right < N)
		{
			PartSum += Data[right];
			right++;
		}

		if (PartSum == M)
		{
			Count++;
		}
		PartSum -= Data[left];
	}

	std::cout << Count;

	return 0;
}