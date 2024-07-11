//문제 주소 : https://www.acmicpc.net/problem/1753

#include <iostream>
#include <vector>
#include <queue>

int VertexCount, EdgeCount;
std::vector<std::vector<std::pair<int, int>>> LinkInfos; //LinkInfo[from] = set::(Weight, To)

std::vector<int> Dij(int StartNode)
{
	std::priority_queue<std::pair<int, int>> pq;
	std::vector<int> Dist;
	Dist.resize(VertexCount, INT32_MAX);
	Dist[StartNode] = 0;

	pq.push(std::make_pair(-Dist[StartNode], StartNode));

	while (!pq.empty())
	{
		int CurCost = -pq.top().first;
		int CurNode = pq.top().second;

		pq.pop();

		if (Dist[CurNode] < CurCost)
		{
			continue;
		}

		for (auto LinkInfo : LinkInfos[CurNode])
		{
			int LinkCost = LinkInfo.first;
			int LinkNode = LinkInfo.second;
			int ViaCost = LinkCost + CurCost;

			if (ViaCost < Dist[LinkNode])
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

	std::cin >> VertexCount >> EdgeCount;
	int Start;
	std::cin >> Start;
	
	LinkInfos.resize(VertexCount);

	for (int i = 0; i < EdgeCount; i++)
	{
		int From, To, Weight;
		std::cin >> From >> To >> Weight;

		LinkInfos[From - 1].push_back(std::make_pair(Weight, To - 1));
	}

	std::vector<int> Answer = Dij(Start - 1);

	for (auto i : Answer)
	{
		if (i == INT32_MAX)
		{
			std::cout << "INF" << '\n';
			continue;
		}

		std::cout << i << '\n';
	}

	return 0;
}