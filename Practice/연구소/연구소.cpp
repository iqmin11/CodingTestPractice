#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <list>

struct Node
{
	static std::pair<int, int> GridSize;
	static std::list<std::pair<int, int>> StartPos;
	static const int Xif[];
	static const int Yif[];


	Node(std::pair<int, int> _Pos)
		: Pos(_Pos)
	{
		SetLinkNodes();
	}

	void SetLinkNodes()
	{
		for (int i = 0; i < 4; i++)
		{
			int tempX = Pos.first + Xif[i];
			int tempY = Pos.second + Yif[i];

			if (tempX < 0 || tempY < 0 || tempX >= GridSize.first || tempY >= GridSize.second)
			{
				continue;
			}

			LinkNodes.insert(std::make_pair(tempX, tempY));
		}
	}

	std::pair<int, int> Pos = {};
	std::set<std::pair<int, int>> LinkNodes;
	int NodeType = 0;
	bool IsVisit = false;
};

const int Node::Xif[] = {1,0,-1,0};
const int Node::Yif[] = {0,1,0,-1};
std::pair<int, int> Node::GridSize = {0,0};
std::vector<std::vector<Node>> Grid = std::vector<std::vector<Node>>();
std::list<std::pair<int, int>> Node::StartPos;
std::vector<std::pair<int, int>> SafeAreas;

void DFS(std::list<std::pair<int, int>> _StartPos)
{
	for (auto& i : _StartPos)
	{
		std::list<std::pair<int, int>> TempStartPos;
		if (!Grid[i.second][i.first].IsVisit)
		{
			Grid[i.second][i.first].IsVisit = true;
			Grid[i.second][i.first].NodeType = 2;
			//std::cout << i.first << "," << i.second << std::endl;
			for (auto& j : Grid[i.second][i.first].LinkNodes)
			{
				TempStartPos.push_back(std::make_pair(j.first, j.second));
			}
			DFS(TempStartPos);
		}
	}
}

int CountZero()
{
	int result = 0;
	for (int y = 0; y < Grid.size(); y++)
	{
		for (int x = 0; x < Grid[y].size(); x++)
		{
			if (Grid[y][x].NodeType == 0)
			{
				result++;
			}
		}
	}
	return result;
}



int main()
{
	std::cin >> Node::GridSize.second >> Node::GridSize.first;

	Grid.resize(Node::GridSize.second);
	for (int y = 0; y < Grid.size(); y++)
	{
		Grid[y].reserve(Node::GridSize.first);
	}

	SafeAreas.reserve(Node::GridSize.second * Node::GridSize.first);

	for (int y = 0; y < Grid.size(); y++)
	{
		for (int x = 0; x < Grid[y].capacity(); x++)
		{
			Grid[y].emplace_back(Node(std::make_pair(x, y)));
			int NodeType;
			std::cin >> NodeType;
			if (NodeType == 2) //시작위치 저장
			{
				Node::StartPos.emplace_back(std::make_pair(x, y));
			}

			if (NodeType == 1) //장애물 저장
			{
				Grid[y][x].IsVisit = true;
			}

			if (NodeType == 0)
			{
				SafeAreas.emplace_back(std::make_pair(x, y)); //0의 위치 저장
			}

			Grid[y][x].NodeType = NodeType;
		}
	}

	//safearea 세개 뽑기;
	std::vector<int> Index;
	Index.resize(SafeAreas.size(), 0);
	Index[0] = 1;
	Index[1] = 1;
	Index[2] = 1;
	std::sort(Index.begin(), Index.end());
	std::set<int> SafeCount;
	std::vector<std::vector<Node>> CopyGrid = std::vector<std::vector<Node>>(Grid); //원본 저장

	while (std::next_permutation(Index.begin(), Index.end())) //경우의수 돌리기
	{
		for (int i = 0; i < Index.size(); i++) 
		{
			int tempindex = -1;
			if (Index[i] == 1)// 1 위치 검색
			{
				Grid[SafeAreas[i].second][SafeAreas[i].first].IsVisit = true;
				Grid[SafeAreas[i].second][SafeAreas[i].first].NodeType = 1; //저장된 위치 벽 세우기
			}
		}

		DFS(Node::StartPos); //DFS
		SafeCount.insert(CountZero()); //SafeArea 개수 인서트

		for (int y = 0; y < Grid.size(); y++) //초기화
		{
			for (int x = 0; x < Grid[y].size(); x++)
			{
				Grid[y][x] = CopyGrid[y][x];
			}
		}
	}
	
	std::cout << *SafeCount.rbegin(); //가장 큰수 출력

	return 0;
}