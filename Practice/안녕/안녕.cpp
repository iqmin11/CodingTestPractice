//문제 주소 : https://www.acmicpc.net/problem/1535

#include <iostream>
#include <vector>

int N;
std::vector<int> Health;
std::vector<int> Pleasure;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::vector<std::vector<int>> DP;
	std::cin >> N;
	Health.resize(N + 1);

	for (int i = 1; i <= N; i++)
	{
		std::cin >> Health[i];
	}

	Pleasure.resize(N + 1);
	for (int i = 1; i <= N; i++)
	{
		std::cin >> Pleasure[i];
	}
	
	DP.resize(N + 1);
	for (int i = 0; i <= N; i++)
	{
		DP[i].resize(100);
	}
	
	int Answer = INT32_MIN;

	for (int i = 1; i <= N; i++)
	{
		for (int p = 0; p <= 99; p++)
		{
			if (p < Health[i])
			{
				DP[i][p] = DP[i - 1][p];
			}
			else
			{
				DP[i][p] = std::max(DP[i - 1][p], DP[i - 1][p - Health[i]] + Pleasure[i]);
			}

			Answer = std::max(Answer, DP[i][p]);
		}
	}

	std::cout << Answer;

	return 0;
}