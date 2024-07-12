//문제 주소 : https://www.acmicpc.net/problem/1238

#include <iostream>
#include <vector>
#include <queue>

int VertexCount, EdgeCount, Party;
std::vector<std::vector<std::pair<int, int>>> LinkNodeInfos; 
std::vector<std::vector<std::pair<int, int>>> ReverseLinkNodeInfos; 

std::vector<int> Dijk(int Party, bool IsReverse)
{
	std::vector<std::vector<std::pair<int, int>>>* NodeInfos = &LinkNodeInfos;

	if (IsReverse)
	{
		NodeInfos = &ReverseLinkNodeInfos;
	}

	std::vector<int> Dist;
	Dist.resize(VertexCount, INT32_MAX);
	Dist[Party] = 0;

	std::priority_queue<std::pair<int, int>> pq;
	pq.push(std::make_pair(-Dist[Party], Party));

	while (!pq.empty())
	{
		int CurCost = -pq.top().first;
		int CurNode = pq.top().second;

		pq.pop();

		if (CurCost > Dist[CurNode])
		{
			continue;
		}

		for (auto LinkInfo : (*NodeInfos)[CurNode])
		{
			int LinkCost = LinkInfo.first;
			int LinkNode = LinkInfo.second;

			int ViaCost = LinkCost + CurCost;

			if (ViaCost < Dist[LinkNode])
			{
				Dist[LinkNode] = ViaCost;
				pq.push(std::make_pair(-ViaCost, LinkNode));
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

	std::cin >> VertexCount >> EdgeCount >> Party;

	LinkNodeInfos.resize(EdgeCount);
	ReverseLinkNodeInfos.resize(EdgeCount);

	for (int i = 0; i < EdgeCount; i++)
	{
		int From, To, Time;

		std::cin >> From >> To >> Time;
		From--;
		To--;
		LinkNodeInfos[From].push_back(std::make_pair(Time, To));
		ReverseLinkNodeInfos[To].push_back(std::make_pair(Time, From));
	}

	std::vector<int> Dist = Dijk(Party - 1, false);
	std::vector<int> ReverseDist = Dijk(Party - 1, true);

	int Answer = INT32_MIN;
	for (int i = 0; i < VertexCount; i++)
	{
		Answer = std::max(Answer, Dist[i] + ReverseDist[i]);
	}

	std::cout << Answer;

	return 0;
}