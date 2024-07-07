//문제 주소 : https://www.acmicpc.net/problem/1495

#include <iostream>
#include <vector>
#include <set>

int N, S, M;
std::vector<int> Arr;
std::vector<std::set<int, std::greater<int>>> DP;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> S >> M;

	Arr.resize(N);
	DP.resize(N + 1);

	for (int i = 0; i < N; i++)
	{
		std::cin >> Arr[i];
	}

	//DP[a] -> S에서 a번째 연산으로 나올 수 있는 모든 수

	DP[0].insert(S);

	for (int t = 0; t < N; t++)
	{
		for (auto i : DP[t])
		{
			for (int j = -1; j <= 1; j += 2)
			{
				int CheckSound = i + (Arr[t] * j);

				if (CheckSound < 0 || CheckSound > M)
				{
					continue;
				}

				DP[t + 1].insert(CheckSound);
			}
		}
	}

	if (!DP[N].empty())
	{
		std::cout << *(DP[N].begin());
	}
	else
	{
		std::cout << -1;
	}

	return 0;
}