//문제 주소 : https://www.acmicpc.net/problem/18870

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;
	std::vector<std::pair<int, int>> Arr(N);

	for (int i = 0; i < N; i++)
	{
		Arr[i].first = i;
		std::cin >> Arr[i].second;
	}

	std::sort(Arr.begin(), Arr.end(), [](std::pair<int, int> Left, std::pair<int, int> Right)
		{
			return Left.second < Right.second;
		});

	std::vector<std::pair<int, int>> DP(N);
	DP[0] = std::make_pair(Arr[0].first, 0);

	for (int i = 1; i < N; i++)
	{
		DP[i].first = Arr[i].first;

		if (Arr[i].second == Arr[i - 1].second)
		{
			DP[i].second = DP[i - 1].second;
			continue;
		}
	
		DP[i].second = DP[i - 1].second + 1;
	}

	std::sort(DP.begin(), DP.end());

	for (int i = 0; i < N; i++)
	{
		std::cout << DP[i].second << ' ';
	}

	return 0;
}