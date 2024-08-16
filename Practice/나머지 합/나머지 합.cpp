//문제 주소 : https://www.acmicpc.net/problem/10986

#include <iostream>
#include <map>

int N, M;
long long DP[1000001];
long long ModDP[1000001];
std::map<long long, long long> ModCount;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	std::cin >> M;

	for (int i = 1; i <= N; i++)
	{
		int temp;
		std::cin >> temp;
		DP[i] = DP[i - 1] + temp;
	}

	for (int i = 1; i <= N; i++)
	{
		ModDP[i] = DP[i] % M;
		ModCount[ModDP[i]]++;
	}

	long long Answer = 0;
	Answer += ModCount[0];

	for (auto i : ModCount)
	{
		Answer += i.second * (i.second - 1) / 2;
	}

	std::cout << Answer;

	return 0;
}