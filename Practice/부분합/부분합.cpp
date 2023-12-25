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
	int lenth = INT32_MAX;

	for (int left = 0; left < N; left++)
	{
		while (PartSum < M && right < N)
		{
			PartSum += Data[right];
			right++;
		}

		if (PartSum >= M)
		{
			lenth = std::min(lenth, right - left);
		}
		PartSum -= Data[left];
	}

	if (lenth == INT32_MAX)
	{
		lenth = 0;
	}

	std::cout << lenth;

	return 0;
}