//https://www.acmicpc.net/problem/11437

#include <iostream>
#include <vector>
#include <set>
#include <queue>

std::vector<int> Depth; // Depth[a] = 노드 a의 깊이 // 초기화는 -1, 만약 추가되지 않았다면 -1이겠죠
std::vector<int> Parent; // Parent[a] = 노드 a의 부모

std::vector<std::set<int>> LinkNodes;

void BFS()
{
	Depth[0] = 0;
	std::queue<int> q;

	q.push(0);

	while (!q.empty())
	{
		int CurNode = q.front();
		q.pop();

		for (auto i : LinkNodes[CurNode])
		{
			if (Depth[i] != -1)
			{
				continue;
			}

			Depth[i] = Depth[CurNode] + 1;
			Parent[i] = CurNode;
			q.push(i);
		}
	}
}

int main()
{
	int N;
	std::cin >> N;
	Depth.resize(N, -1);
	Parent.resize(N);
	LinkNodes.resize(N);

	for (size_t i = 0; i < N-1; i++)
	{
		int Node1;
		int Node2;
		
		std::cin >> Node1 >> Node2;
		--Node1;
		--Node2;

		LinkNodes[Node1].insert(Node2);
		LinkNodes[Node2].insert(Node1);
	}

	BFS();

	int M;
	std::cin >> M;

	std::vector<int> CommonParents;
	CommonParents.reserve(M);

	for (size_t i = 0; i < M; i++)
	{
		int Node1;
		int Node2;

		std::cin >> Node1 >> Node2;
		--Node1;
		--Node2;

		while (Node1 != Node2)
		{
			if (Depth[Node1] != Depth[Node2])
			{
				if (Depth[Node1] > Depth[Node2])
				{
					Node1 = Parent[Node1];
				}
				else
				{
					Node2 = Parent[Node2];
				}
			}
			else
			{
				Node1 = Parent[Node1];
				Node2 = Parent[Node2];
			}
		}

		CommonParents.push_back(Node1);
	}

	for (size_t i = 0; i < M; i++)
	{
		std::cout << CommonParents[i] + 1 << "\n";
	}
}