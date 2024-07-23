//문제 주소 : https://www.acmicpc.net/problem/1916

#include <iostream>
#include <vector>
#include <set>
#include <queue>

int N, M;
std::vector<std::vector<std::pair<int, int>>> LinkedInfo; //a c노드가 비용 b로 이어져있음

std::vector<int> Dijk(int StartNode)
{
	std::vector<int> Dist;
	Dist.resize(N + 1, INT32_MAX);

	Dist[StartNode] = 0;

	std::priority_queue<std::pair<int, int>> pq;
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

		for (auto CheckInfo : LinkedInfo[CurNode])
		{
			int CheckCost = CheckInfo.first;
			int CheckNode = CheckInfo.second;

			int ViaCost = CheckCost + CurCost;

			if (Dist[CheckNode] > ViaCost)
			{
				Dist[CheckNode] = ViaCost;
				pq.push(std::make_pair(-Dist[CheckNode], CheckNode));
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

	int StartNode, DestNode;
	std::cin >> N >> M;

	LinkedInfo.resize(N + 1);

	for (int i = 0; i < M; i++)
	{
		int From, To, Cost;
		std::cin >> From >> To >> Cost;

		LinkedInfo[From].push_back(std::make_pair(Cost, To));
	}

	std::cin >> StartNode >> DestNode;

	std::vector<int> Result = Dijk(StartNode);

	std::cout << Result[DestNode];

	return 0;
}