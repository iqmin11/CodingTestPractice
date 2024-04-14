#include <iostream>
#include <vector>
#include <tuple>

const int INF = 10000000001; // 가중치 합의 최대 + 1값
int N, M; //노드의 갯수, 간선의 갯수
std::vector<std::tuple<int, int, long long>> EdgeInfo; //이어지는 노드쌍 정보, 비용

std::vector<long long> BellmanFord(int Start)
{
	std::vector<long long> Dist(N, INF);
	Dist[Start] = 0;

	for (int i = 0; i < N - 1; i++)
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

	for (auto& Edge : EdgeInfo) //음수 가중치 사이클 검사
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
			return {};
		}
	}

	return Dist;
}
