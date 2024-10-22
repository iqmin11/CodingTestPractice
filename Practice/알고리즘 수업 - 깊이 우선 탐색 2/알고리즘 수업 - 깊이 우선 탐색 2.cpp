//문제 주소 : https://www.acmicpc.net/problem/24480

#include <iostream>
#include <vector>
#include <set>

int V, E, R;
std::vector<std::set<int, std::greater<int>>> LinkInfo; //LinkInfo[a] = a랑 연결된 노드들
bool IsVisit[100001];
std::vector<int> VisitOrder;
int Order = 0;

void DFS(int CurNode)
{
	IsVisit[CurNode] = true;
	VisitOrder[CurNode] = ++Order;

	for (auto LinkNode : LinkInfo[CurNode])
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

	std::cin >> V >> E >> R;
	LinkInfo.resize(V);
	for (int i = 0; i < E; i++)
	{
		int From, To;
		std::cin >> From >> To;
		From--; To--;
		
		LinkInfo[From].insert(To);
		LinkInfo[To].insert(From);
	}

	VisitOrder.resize(V, 0);

	DFS(R - 1);
	for (int i = 0; i < V; i++)
	{
		std::cout << VisitOrder[i] << '\n';
	}

	return 0;
}