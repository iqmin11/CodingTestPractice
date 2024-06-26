//https://www.acmicpc.net/problem/11438

#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> Depth; 
std::vector<std::vector<int>> Parent; // Parent[a][b] a로부터 2^b번째 위에 있는 조상 
std::vector<std::vector<int>> LinkNodes;
int Max = INT32_MIN;
int N, M;

void DFS(int _CurNode, int _Parent = -1)
{
	Parent[_CurNode][0] = _Parent;

	if (_Parent == -1)
	{
		Depth[_CurNode] = 0;
	}
	else
	{
		Depth[_CurNode] = Depth[_Parent] + 1;
	}

	for (auto& NextNode : LinkNodes[_CurNode])
	{
		if (Depth[NextNode] != -1)
		{
			continue;
		}

		DFS(NextNode, _CurNode);
	}
}

void Connection()
{
	for (int i = 1; i < Max; i++)
	{
		for (int Node = 1; Node <= N; Node++)
		{
			if (Parent[Node][i - 1] == -1)
			{
				continue;
			}
			Parent[Node][i] = Parent[Parent[Node][i - 1]][i - 1];
		}
	}
}

int LCA(int Node1, int Node2)
{
	if (Depth[Node1] < Depth[Node2])
	{
		std::swap(Node1, Node2);
	}

	int Differ = Depth[Node1] - Depth[Node2];
	
	for (int i = 0; Differ != 0; i++)
	{
		if (Differ & 1)
		{
			Node1 = Parent[Node1][i];
		}
		Differ >>= 1;
	}

	if (Node1 != Node2)
	{
		for (int i = Max - 1; i >= 0; --i)
		{
			if (Parent[Node1][i] != -1 && Parent[Node1][i] != Parent[Node2][i])
			{
				Node1 = Parent[Node1][i];
				Node2 = Parent[Node2][i];
			}
		}

		Node1 = Parent[Node1][0];
	}

	return Node1;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	Max = static_cast<int>(std::ceil(std::log2(N))); //모든 노드가 일렬로 위치해있다고 가정했을시, 한 노드가 가져야 할 최대 부모 배열의 크기

	Depth.resize(N + 1, -1);
	Parent.resize(N + 1);
	for (int i = 0; i < N + 1; i++)
	{
		Parent[i].resize(Max, -1);
	}
	LinkNodes.resize(N + 1);

	for (int i = 0; i < N - 1; i++)
	{
		int Node1, Node2;

		std::cin >> Node1 >> Node2;

		LinkNodes[Node1].push_back(Node2);
		LinkNodes[Node2].push_back(Node1);
	}

	DFS(1);
	Connection();
	
	std::cin >> M;
	std::vector<int> CommonParent;
	CommonParent.reserve(M);
	for (int i = 0; i < M; i++)
	{
		int Node1;
		int Node2;

		std::cin >> Node1 >> Node2;
		CommonParent.push_back(LCA(Node1, Node2));
	}

	for (auto i : CommonParent)
	{
		std::cout << i << '\n';
	}

}