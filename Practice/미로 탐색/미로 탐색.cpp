#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <queue>

struct Node
{
	static std::pair<int, int> GridSize;

	Node(std::pair<int, int> _Pos)
		: Pos(_Pos)
	{
		SetLinkNode();
	}

	void SetLinkNode()
	{
		if (Pos.first + 1 < GridSize.first)
			LinkNodes.insert(std::make_pair(Pos.first + 1, Pos.second));
		if (Pos.second + 1 < GridSize.second)
			LinkNodes.insert(std::make_pair(Pos.first, Pos.second + 1));
		if (Pos.first - 1 >= 0)
			LinkNodes.insert(std::make_pair(Pos.first - 1, Pos.second));
		if (Pos.second - 1 >= 0)
			LinkNodes.insert(std::make_pair(Pos.first, Pos.second - 1));
	}

	std::pair<int, int> Pos = { 0,0 };
	std::set<std::pair<int, int>> LinkNodes = std::set<std::pair<int, int>>();
	bool IsVisit = false;
	int MoveCount = 0;
};

std::pair<int, int> Node::GridSize = { 0,0 };
std::vector<std::vector<Node>> Grid = std::vector<std::vector<Node>>();

//void DFS(std::pair<int, int> _StartPos)
//{
//	Node& CurNode = Grid[_StartPos.second][_StartPos.first];
//	if (!CurNode.IsVisit)
//	{
//		CurNode.IsVisit = true;
//		for (auto& i : CurNode.LinkNode)
//		{
//			DFS(i);
//		}
//	}
//}

int BFS(std::pair<int, int> _StartPos, std::pair<int, int> _Destination)
{
	std::queue<std::pair<int, int>> Q;
	Grid[_StartPos.second][_StartPos.first].IsVisit = true;
	Grid[_StartPos.second][_StartPos.first].MoveCount = 1;
	Q.push(_StartPos);
	//std::cout << _StartPos.first << "," << _StartPos.second << " Depth : " << Grid[_StartPos.second][_StartPos.first].MoveCount << std::endl;

	while (!Q.empty())
	{
		std::pair<int, int> CurCheckPos = Q.front();
		Q.pop();
		for (auto& LinkNode : Grid[CurCheckPos.second][CurCheckPos.first].LinkNodes)
		{
			if (!Grid[LinkNode.second][LinkNode.first].IsVisit)
			{
				Grid[LinkNode.second][LinkNode.first].IsVisit = true;
				Grid[LinkNode.second][LinkNode.first].MoveCount = Grid[CurCheckPos.second][CurCheckPos.first].MoveCount + 1;
				Q.push(LinkNode);
				//std::cout << LinkNode.first << "," << LinkNode.second << " Depth : " << Grid[LinkNode.second][LinkNode.first].MoveCount << std::endl;
				if (LinkNode == _Destination) // 목적지까지의 경로를 찾았을 경우
				{
					return Grid[LinkNode.second][LinkNode.first].MoveCount;
				}
			}
		}
	}
	return -1; // 목적지에 다다르지 못했다는 뜻
}

int main()
{
	std::cin >> Node::GridSize.second >> Node::GridSize.first;

	Grid.resize(Node::GridSize.second);
	for (int y = 0; y < Grid.size(); y++)
	{
		Grid[y].reserve(Node::GridSize.first);
	}

	for (int y = 0; y < Grid.size(); y++)
	{
		std::string path;
		std::cin >> path;
		for (int x = 0; x < Grid[y].capacity(); x++)
		{
			Grid[y].emplace_back(Node(std::make_pair(x,y)));
			Grid[y][x].IsVisit = !static_cast<bool>(path[x] - '0');
		}
	}

	std::pair<int, int> StartPos = { 0,0 };
	std::pair<int, int> Destination = { Node::GridSize.first - 1 ,Node::GridSize.second - 1 };

	std::cout << BFS(StartPos, Destination);

	return 0;
}