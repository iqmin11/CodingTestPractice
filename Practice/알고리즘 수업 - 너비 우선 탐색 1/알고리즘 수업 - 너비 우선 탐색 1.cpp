#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <iterator>

std::vector<std::set<int>> LinkNodes;
std::vector<bool> IsVisit;
std::vector<int> Answer; //Answer[a] 정점 a의 방문 순서


void BFS(int _Start)
{
	std::queue<int> q;

	IsVisit[_Start] = true;
	q.push(_Start);
	int Count = 0;

	while (!q.empty())
	{
		int Check = q.front();

		q.pop();
		Answer[Check] = Count++;

		for (auto& LinkNode : LinkNodes[Check])
		{
			if (!IsVisit[LinkNode])
			{
				IsVisit[LinkNode] = true;
				q.push(LinkNode);
			}
		}
	}
}

int main()
{
	int N, M, R;
	std::cin >> N >> M >> R;

	LinkNodes.resize(N);
	IsVisit.resize(N, false);
	Answer.resize(N, -1);

	for (size_t i = 0; i < M; i++)
	{
		int u, v;
		std::cin >> u >> v;

		LinkNodes[u-1].insert(v-1);
		LinkNodes[v-1].insert(u-1);
	}

	BFS(R-1);

	for (auto& i : Answer)
	{
		std::cout << i + 1 << "\n";
	}
}