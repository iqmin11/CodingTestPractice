//문제 주소 : https://www.acmicpc.net/problem/14267 

#include <iostream>
#include <vector>

int N, M;
std::vector<int> Parent;
std::vector<int> DP;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;

	Parent.resize(N + 1);

	for (int i = 1; i <= N; i++)
	{
		std::cin >> Parent[i];
	}

	Parent[1] = 0;
	DP.resize(N + 1, 0);

	for (int i = 0; i < M; i++)
	{
		int GoodPerson, GoodScore;
		std::cin >> GoodPerson >> GoodScore;

		DP[GoodPerson] += GoodScore;
	}

	for (int i = 1; i <= N; i++)
	{
		DP[i] += DP[Parent[i]];
	}

	for (int i = 1; i <= N; i++)
	{
		std::cout << DP[i] << ' ';
	}

	return 0;
}