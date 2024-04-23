//https://www.acmicpc.net/problem/5972

#include <iostream>
#include <vector>
#include <set>
#include <queue>

int N, M;
std::vector<std::set<std::pair<int, int>>> LinkNodes;

std::vector<int> DijkstraPQ(int _Start)
{
	std::vector<int> Dist;
	Dist.resize(N, INT32_MAX);
	Dist[_Start] = 0;

	std::priority_queue<std::pair<int, int>> pq;
	pq.push({ -Dist[_Start] , _Start });
	while (!pq.empty())
	{
		int CurCost = -pq.top().first;
		int CurIndex = pq.top().second;

		pq.pop();

		if (Dist[CurIndex] < CurCost)
		{
			continue;
		}

		for (auto& LinkNode : LinkNodes[CurIndex])
		{
			int ViaCost = CurCost + LinkNode.first;
			if (Dist[LinkNode.second] > ViaCost)
			{
				Dist[LinkNode.second] = ViaCost;
				pq.push({ -Dist[LinkNode.second], LinkNode.second });
			}
		}
	}

	return Dist;
}

int main()
{
	std::cin >> N >> M;
	LinkNodes.resize(N);

	for (int i = 0; i < M; i++)
	{
		int a, b, c;

		std::cin >> a >> b >> c;

		LinkNodes[a - 1].insert(std::make_pair(c, b - 1));
		LinkNodes[b - 1].insert(std::make_pair(c, a - 1));
	}

	std::vector<int> Answer = DijkstraPQ(0);

	std::cout << Answer.back();
}