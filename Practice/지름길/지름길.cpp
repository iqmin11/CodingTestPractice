//문제 주소 : https://www.acmicpc.net/problem/1446

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>

int N, Dest;
std::map<int, std::set<std::pair<int, int>>> LinkedInfos;
std::set<int> NodeInfo;

std::map<int, int> Dij(int StartNode)
{
	std::priority_queue<std::pair<int, int>> pq;
	std::map<int, int> Dist; //Dist[a] 는 StartNode에서의 최소 코스트
	for (auto Info : NodeInfo)
	{
		Dist.insert(std::make_pair(Info, INT32_MAX));
	}
	
	Dist[StartNode] = 0;

	pq.push(std::make_pair(-Dist[StartNode], StartNode));

	while (!pq.empty())
	{
		int CurCost = -pq.top().first;
		int CurNode = pq.top().second;

		pq.pop();

		if (CurCost > Dist[CurNode])
		{
			continue;
		}

		for (auto& LinkInfo : LinkedInfos[CurNode])
		{
			int LinkCost = -LinkInfo.first;
			int LinkNode = LinkInfo.second;

			int ViaCost = LinkCost + CurCost;
			if (Dist[LinkNode] > ViaCost)
			{
				Dist[LinkNode] = ViaCost;
				pq.push(std::make_pair(-Dist[LinkNode], LinkNode));
			}
		}
	}

	return Dist;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> Dest;

	for (int i = 0; i < N; i++)
	{
		int From, To, Cost;
		std::cin >> From >> To >> Cost;

		LinkedInfos[From].insert(std::make_pair(-Cost, To));

		NodeInfo.insert(From);
		NodeInfo.insert(To);
	}

	NodeInfo.insert(0);
	NodeInfo.insert(Dest);

	for (auto FromIter = NodeInfo.begin(); FromIter != std::prev(NodeInfo.end()); ++FromIter)
	{
		for (auto ToIter = std::next(FromIter); ToIter != NodeInfo.end(); ++ToIter)
		{
			LinkedInfos[*FromIter].insert(std::make_pair(-(*ToIter - *FromIter), *ToIter));
		}
	}

	std::cout << Dij(0)[Dest];

	return 0;
}