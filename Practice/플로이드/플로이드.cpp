//https://www.acmicpc.net/problem/11404

#include <iostream>
#include <vector>

int N, M;
std::vector<std::vector<int>> Cost;
const int INF = 100001 * 100; //초기화 값에 대한 고찰

std::vector<std::vector<int>> FW()
{
	std::vector<std::vector<int>> Dist = Cost;

	for (size_t k = 0; k < N; k++)
	{
		for (size_t j = 0; j < N; j++)
		{
			for (size_t i = 0; i < N; i++)
			{
				Dist[i][j] = std::min(Dist[i][j], Dist[i][k] + Dist[k][j]);
			}
		}
	}

	return Dist;
}

int main()
{

	std::cin >> N >> M;

	Cost.resize(N);
	for (size_t i = 0; i < N; i++)
	{
		Cost[i].resize(N, INF);
		Cost[i][i] = 0;
	}

	for (size_t i = 0; i < M; i++)
	{
		int City1, City2, CostValue;
		std::cin >> City1 >> City2 >> CostValue;
		Cost[City1 - 1][City2 - 1] = std::min(CostValue, Cost[City1 - 1][City2 - 1]);
	}

	std::vector<std::vector<int>> Answer = FW();

	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			if (Answer[i][j] == INF)
			{
				Answer[i][j] = 0;
			}

			std::cout << Answer[i][j] << " ";
		}
		std::cout << std::endl;
	}
}