//문제 주소 : https://www.acmicpc.net/problem/11659

#include <iostream>
#include <vector>

inline int PrefixSum(int Start, int End, const std::vector<int>& SumDP)
{
	return SumDP[End] - SumDP[Start - 1];
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, M;
	std::cin >> N >> M;

	std::vector<int> SumDP(N + 1, 0);
	for (int i = 1; i <= N; i++)
	{
		std::cin >> SumDP[i];
		SumDP[i] += SumDP[i - 1];
	}

	for (int i = 0; i < M; i++)
	{
		int Start, End;
		std::cin >> Start >> End;

		std::cout << PrefixSum(Start, End, SumDP) <<'\n';
	}

	return 0;
}