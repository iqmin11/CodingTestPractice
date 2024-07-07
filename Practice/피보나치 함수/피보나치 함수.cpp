//문제 주소 : https://www.acmicpc.net/problem/1003

#include <iostream>

std::pair<int, int> DP[41]; //0의 갯수, 1의 갯수

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	DP[0] = { 1,0 };
	DP[1] = { 0,1 };

	for (int i = 2; i <= 40; i++)
	{
		DP[i].first = DP[i - 1].first + DP[i - 2].first;
		DP[i].second = DP[i - 1].second + DP[i - 2].second;
	}

	int T;
	std::cin >> T;

	while (T-- > 0)
	{
		int N;
		std::cin >> N;
		std::cout << DP[N].first << ' ' << DP[N].second << '\n';
	}

	return 0;
}