//문제 주소 : https://www.acmicpc.net/problem/11053

#include <iostream>
#include <vector>

int DP[1001] = {};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;

	std::cin >> N;

	std::vector<int> Arr;
	Arr.resize(N + 1, 0);

	for (int i = 1; i <= N; i++)
	{
		std::cin >> Arr[i];
	}

	int Answer = INT32_MIN;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (Arr[i] > Arr[j])
			{
				DP[i] = std::max(DP[i], DP[j] + 1);
			}
		}

		Answer = std::max(Answer, DP[i]);
	}

	std::cout << Answer;

	return 0;
}