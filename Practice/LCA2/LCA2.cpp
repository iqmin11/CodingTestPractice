//https://www.acmicpc.net/problem/11438

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <cmath>

std::vector<int> Depth; 
std::vector<std::vector<int>> Parent;

std::vector<std::vector<int>> LinkNodes;

const int MaxNodeCount = 100001;
const int MaxDepth = static_cast<int>(std::log2(MaxNodeCount));

void DFS(int _CurNode, int _Parent)
{
	Depth[_CurNode] = Depth[_Parent] + 1;

	Parent[_CurNode][0] = _Parent;

	for (size_t i = 1; i < MaxDepth; i++)
	{
		if (Parent[_CurNode][i - 1] == -1)
		{
			continue;
		}

		Parent[_CurNode][i] = Parent[Parent[_CurNode][i - 1]][i - 1];
	}

	for (auto CheckNode : LinkNodes[_CurNode])
	{
		if (Depth[CheckNode] != -1)
		{
			continue;
		}

		DFS(CheckNode, _CurNode);
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;
	++N;
	Depth.resize(N, -1);
	Parent.resize(N);
	for (size_t i = 0; i < N; i++)
	{
		Parent[i].resize(MaxDepth, -1);
	}
	LinkNodes.resize(N);

	for (size_t i = 0; i < N - 1; i++)
	{
		int Node1, Node2;

		std::cin >> Node1 >> Node2;

		LinkNodes[Node1].push_back(Node2);
		LinkNodes[Node2].push_back(Node1);
	}

	DFS(1, 0);

	int M;
	std::cin >> M;

	while (M-- != 0)
	{
		int Node1, Node2;
		std::cin >> Node1 >> Node2;

		if (Depth[Node1] > Depth[Node2])
		{
			if (Depth[Node1] > Depth[Node2])
			{
				std::swap(Node1, Node2);
			}

			for (int i = MaxDepth - 1; i >= 0; i--)
			{
				if (Depth[Node1] <= Depth[Parent[Node2][i]])
				{
					Node2 = Parent[Node2][i];
				}
			}
		}

		int LCA = Node1;

		if (Node1 != Node2)
		{
			for (int i = MaxDepth - 1; i >= 0; i--)
			{
				if (Parent[Node1][i] != Parent[Node2][i])
				{
					Node1 = Parent[Node1][i];
					Node2 = Parent[Node2][i];
				}
				LCA = Parent[Node1][i];
			}
		}
		std::cout << LCA << "\n";
	}

}