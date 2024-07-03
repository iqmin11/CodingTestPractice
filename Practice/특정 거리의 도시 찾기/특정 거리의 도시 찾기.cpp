//문제 주소 : https://www.acmicpc.net/problem/18352

#include <iostream>
#include <vector>
#include <set>
#include <queue>

const int INF = 300001;

int N, M, K, X;

std::vector<std::set<std::pair<int, int>>> LinkedNodesInfo; //LinkedNodesInfo[a]는 a와 연결된 노드정보 (Cost, NodeIndex)

std::vector<int> Dij(int StartNode)
{
	std::vector<int> Dist; //Dist[a]는 Start에서 a로 가는 최소비용
	Dist.resize(N, INF);
	Dist[StartNode] = 0;

	std::priority_queue<std::pair<int, int>> pq; //-Cost, NodeIndex

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

		for (auto LinkNodeInfo : LinkedNodesInfo[CurNode])
		{
			int LinkCost = LinkNodeInfo.first;
			int LinkNode = LinkNodeInfo.second;

			int ViaCost = CurCost + LinkCost;
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

	std::cin >> N >> M >> K >> X;

	LinkedNodesInfo.resize(N);

	for (int i = 0; i < M; i++)
	{
		int From, To;
		std::cin >> From >> To;
		From--;
		To--;

		LinkedNodesInfo[From].insert({1, To});
	}

	std::vector<int> Dist = Dij(X - 1);
	bool IsNothing = true;

	for (size_t i = 0; i < Dist.size(); i++)
	{
		if (Dist[i] == K)
		{
			std::cout << i + 1 << '\n';
			IsNothing = false;
		}
	}

	if (IsNothing)
	{
		std::cout << -1;
	}

	return 0;
}