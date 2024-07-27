//문제 주소 : https://www.acmicpc.net/problem/2565

#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector<std::pair<int, int>> Lines;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	Lines.resize(N);
	for (int i = 0; i < N; i++)
	{
		std::cin >> Lines[i].first >> Lines[i].second;
	}

	std::sort(Lines.begin(), Lines.end());

	std::vector<int> DP(N, 1); //가장 긴 증가하는 부분수열 (연결된곳이 증가하는 부분수열이면 겹치지 않음)
	int Answer = INT32_MIN;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (Lines[i].second > Lines[j].second)
			{
				DP[i] = std::max(DP[i], DP[j] + 1);
				Answer = std::max(Answer, DP[i]);
			}
		}
	}

	Answer = N - Answer;

	std::cout << Answer;

	return 0;
}