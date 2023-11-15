#include <iostream>
#include <vector>

int DP[100001];

int main()
{
	DP[1] = 1;
	DP[2] = 2;
	DP[3] = 4;

	int N;
	std::cin >> N;

	std::vector<int> vec;
	vec.resize(N);
	int Max = INT32_MIN;
	for (int i = 0; i < N; i++)
	{
		std::cin >> vec[i];
		if (Max < vec[i])
		{
			Max = vec[i];
		}
	}
	
	for (int i = 4; i <= Max; i++)
	{
		DP[i] = DP[i - 1] + DP[i - 2] + DP[i - 3];
	}

	for (size_t i = 0; i < N; i++)
	{
		std::cout << DP[vec[i]] << "\n";
	}

	return 0;
}