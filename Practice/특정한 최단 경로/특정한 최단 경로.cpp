//문제 주소 : https://www.acmicpc.net/problem/1504

#include <iostream>
#include <vector>
#include <queue>

//Cost, To
int V, E;
std::vector<std::vector<std::pair<int, int>>> LinkInfo;

std::vector<int> Dijk(int StartNode)
{
	std::vector<int> Dist(V, INT32_MAX); // Dist[a] => StartNode에서 a Node로 가는 최단거리
	Dist[StartNode] = 0;

	std::priority_queue<std::pair<int, int>> pq; // Cost, DestNode;
	pq.push(std::make_pair(-Dist[StartNode], StartNode));

	while (!pq.empty())
	{
		int CurCost = -pq.top().first;
		int CurDestNode = pq.top().second;

		pq.pop();

		if (Dist[CurDestNode] < CurCost)
		{
			continue;
		}

		for (auto LinkNode : LinkInfo[CurDestNode])
		{
			int ViaCost = CurCost + LinkNode.first;
			if (ViaCost < Dist[LinkNode.second])
			{
				Dist[LinkNode.second] = ViaCost;
				pq.push(std::make_pair(-ViaCost, LinkNode.second));
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

	std::cin >> V >> E;
	LinkInfo.resize(V);

	for (int e = 0; e < E; e++)
	{
		int From, To, Cost;
		std::cin >> From >> To >> Cost;
		
		--From;
		--To;

		LinkInfo[From].push_back(std::make_pair(Cost, To));
		LinkInfo[To].push_back(std::make_pair(Cost, From));
	}

	int Via0, Via1;
	std::cin >> Via0 >> Via1;
	--Via0;
	--Via1;
	std::vector<int> FromVia0 = Dijk(Via0);
	std::vector<int> FromVia1 = Dijk(Via1);

	//Comp
	//From Start To Via0  + From Via1 To Dest
	//From Start To Via1  + From Via0 To Dest

	int Comp0 = FromVia0[0] == INT32_MAX || FromVia1[V - 1] == INT32_MAX ? -1 : FromVia0[0] + FromVia1[V - 1];
	int Comp1 = FromVia0[V - 1] == INT32_MAX || FromVia1[0] == INT32_MAX ? -1 : FromVia0[V - 1] + FromVia1[0];
	int Const = FromVia0[Via1] == INT32_MAX ? -1 : FromVia0[Via1];
	std::cout << ((Comp0 == -1 || Comp1 == -1 || Const == -1) ? -1 : (std::min(Comp0, Comp1) + Const));

	return 0;
}