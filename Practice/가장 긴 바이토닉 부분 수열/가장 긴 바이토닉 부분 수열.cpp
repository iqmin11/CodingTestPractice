//문제 주소 : https://www.acmicpc.net/problem/11054

#include <iostream>
#include <vector>

int N;
std::vector<int> Arr;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	Arr.resize(N);
	for (size_t i = 0; i < N; i++)
	{
		std::cin >> Arr[i];
	}

	std::vector<int> DP_Increase(N, 1);
	std::vector<int> DP_Decrease(N, 1);

	int Answer = INT32_MIN;

	for (int i = 0; i < N; i++)
	{
		int ri = N - 1 - i;
		for (int j = 0; j < i; j++)
		{
			int rj = N - 1 - j;
			if (Arr[i] > Arr[j])
			{
				DP_Increase[i] = std::max(DP_Increase[i], DP_Increase[j] + 1);
			}

			if (Arr[ri] > Arr[rj])
			{
				DP_Decrease[ri] = std::max(DP_Decrease[ri], DP_Decrease[rj] + 1);
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		Answer = std::max(DP_Increase[i] + DP_Decrease[i] - 1, Answer);
	}

	std::cout << Answer;

	return 0;
}