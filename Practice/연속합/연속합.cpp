//문제 주소 : https://www.acmicpc.net/problem/1912

#include <iostream>
#include <vector>
#include <deque>

int DP[100001] = {};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;
	std::vector<int> Arr;
	Arr.resize(N + 1);
	for (int i = 1; i <= N; i++)
	{
		std::cin >> Arr[i];
	}

	DP[1] = Arr[1];
	int Answer = DP[1];

	for (int i = 2; i <= N; i++)
	{
		DP[i] = std::max(DP[i - 1] + Arr[i], Arr[i]);
		Answer = std::max(Answer, DP[i]);
	}

	std::cout << Answer;

	return 0;
}