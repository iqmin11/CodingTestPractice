//문제 주소 : https://www.acmicpc.net/problem/1967

#include <iostream>
#include <vector>

int VertexCount, EdgeCount;
std::vector<std::vector<std::pair<int, int>>> LinkNodes;
std::vector<bool> IsVisit;

int CurCost = 0;
int MaxCost = INT32_MIN;
int MaxCostNode = -1;

void Init()
{
	CurCost = 0;
	MaxCost = INT32_MIN;
	MaxCostNode = -1;
	for (int i = 0; i < VertexCount; i++)
	{
		IsVisit[i] = false;
	}
}

void DFS(int CurNode)
{
	IsVisit[CurNode] = true;
	if (MaxCost < CurCost)
	{
		MaxCost = CurCost;
		MaxCostNode = CurNode;
	}

	for (auto i : LinkNodes[CurNode])
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
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> VertexCount;
	EdgeCount = VertexCount - 1;

	LinkNodes.resize(VertexCount);
	IsVisit.resize(VertexCount, false);

	for (int i = 0; i < EdgeCount; i++)
	{
		int ParentNode, ChildNode, Weight;
		std::cin >> ParentNode >> ChildNode >> Weight;
		ParentNode--;
		ChildNode--;

		LinkNodes[ParentNode].push_back(std::make_pair(ChildNode, Weight));
		LinkNodes[ChildNode].push_back(std::make_pair(ParentNode, Weight));
	}

	DFS(0);
	int StartNode = MaxCostNode;
	Init();
	DFS(StartNode);

	std::cout << MaxCost;

	return 0;
}