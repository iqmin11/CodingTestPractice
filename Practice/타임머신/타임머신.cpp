//https://www.acmicpc.net/problem/11657

#include <iostream>
#include <vector>
#include <tuple>

const int INF = 500 * 10000 + 1;

int N, M; //노드의 갯수, 간선의 갯수

std::vector<std::tuple<int, int, long long>> EdgeInfo; //이어지는 노드쌍 정보, 비용

std::vector<long long> BellmanFord(int Start)
{
	std::vector<long long> Dist(N, INF);
	Dist[Start] = 0;

	for (size_t i = 0; i < N - 1; i++)
	{
		for (auto& Edge : EdgeInfo)
		{
			int Start = std::get<0>(Edge);
			int Dest = std::get<1>(Edge);
			long long Cost = std::get<2>(Edge);


			if (Dist[Start] == INF)
			{
				continue;
			}

			if (Dist[Dest] > Dist[Start] + Cost)
			{
				Dist[Dest] = Dist[Start] + Cost;
			}
		}
	}

	for (auto& Edge : EdgeInfo)
	{
		int Start = std::get<0>(Edge);
		int Dest = std::get<1>(Edge);
		long long Cost = std::get<2>(Edge);

		if (Dist[Start] == INF)
		{
			continue;
		}

		if (Dist[Dest] > Dist[Start] + Cost)
		{
			return { 0,-1 };
		}
	}

	return Dist;
}

int main()
{
	std::cin >> N >> M;

	EdgeInfo.reserve(M);

	for (size_t i = 0; i < M; i++)
	{
		int a, b;
		long long c;
		std::cin >> a >> b >> c;
		EdgeInfo.push_back({ a - 1,b - 1,c });
	}

	std::vector<long long> Answer = BellmanFord(0);

	for (size_t i = 1; i < Answer.size(); i++)
	{
		if (Answer[i] == INF)
		{
			Answer[i] = -1;
		}
		std::cout << Answer[i] << '\n';
	}

	return 0;
}