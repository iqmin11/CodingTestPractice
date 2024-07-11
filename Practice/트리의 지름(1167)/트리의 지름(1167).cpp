//문제 주소 : https://www.acmicpc.net/problem/1167

#include <iostream>
#include <vector>

int N;

std::vector<std::vector<std::pair<int, int>>> LinkInfo;
std::vector<bool> IsVisit;

int CurCost = 0;
int MaxCost = INT32_MIN;
int MaxCostNode = -1;
void DFS(int CurNode)
{
	IsVisit[CurNode] = true;
	if (CurCost > MaxCost)
	{
		MaxCost = CurCost;
		MaxCostNode = CurNode;
	}

	for (auto i : LinkInfo[CurNode])
	{
		int LinkNode = i.first;
		int LinkCost = i.second;
		
		if (IsVisit[LinkNode])
		{
			continue;
		}

		CurCost += LinkCost;
		DFS(LinkNode);
		CurCost -= LinkCost;
	}
	IsVisit[CurNode] = false;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	LinkInfo.resize(N + 1);
	IsVisit.resize(N + 1, false);
	for (int i = 0; i < N; i++)
	{
		int CurNode;
		std::cin >> CurNode;
		int LinkNode = -2;
		while (true)
		{
			std::cin >> LinkNode;
			if (LinkNode == -1)
			{
				break;
			}

			int LinkCost;
			std::cin >> LinkCost;
			LinkInfo[CurNode].push_back(std::make_pair(LinkNode, LinkCost));
		}
	}

	DFS(1);
	int LeftEndNode = MaxCostNode;
	MaxCost = INT32_MIN;
	MaxCostNode = -1;
	DFS(LeftEndNode);

	std::cout << MaxCost;

	return 0;
}