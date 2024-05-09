//문제 주소 : https://www.acmicpc.net/problem/11724

#include <iostream>
#include <vector>
#include <set>

std::vector<bool> IsVisit;
std::vector<std::set<int>> LinkedNodes;

void DFS(int CurNode)
{
	IsVisit[CurNode] = true;

	for (auto& LinkNode : LinkedNodes[CurNode])
	{
		if (IsVisit[LinkNode])
		{
			continue;
		}

		DFS(LinkNode);
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, M;

	std::cin >> N >> M;
	IsVisit.resize(N, false);
	LinkedNodes.resize(N);

	for (int i = 0; i < M; i++)
	{
		int Node1, Node2;

		std::cin >> Node1 >> Node2;

		LinkedNodes[Node1 - 1].insert(Node2 - 1);
		LinkedNodes[Node2 - 1].insert(Node1 - 1);
	}

	int Answer = 0;

	for (int i = 0; i < N; i++)
	{
		if (IsVisit[i])
		{
			continue;
		}

		Answer++;
		DFS(i);
	}

	std::cout << Answer;

	return 0;
}