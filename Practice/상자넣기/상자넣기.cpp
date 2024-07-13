//문제 주소 : https://www.acmicpc.net/problem/1965

#include <iostream>
#include <vector>

int N;
std::vector<int> Arr;
int DP[1001]; //증가하는 가장 긴 부분수열 DP[a]

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	Arr.resize(N + 1);

	for (int i = 1; i <= N; i++)
	{
		std::cin >> Arr[i];
	}

	int Answer = INT32_MIN;

	for (int i = 1; i <= N; i++)
	{
		DP[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (Arr[j] < Arr[i])
			{
				DP[i] = std::max(DP[i], DP[j] + 1);
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		Answer = std::max(Answer, DP[i]);
	}

	std::cout << Answer;

	return 0;
}