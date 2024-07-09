//문제 주소 : https://www.acmicpc.net/problem/6497

#include <iostream>
#include <queue>
#include <vector>

int HouseCount, PathCount;
std::priority_queue<std::pair<int, std::pair<int, int>>> PathInfo; //-비용, 연결 노드 
std::vector<int> Parent;

void Init()
{
	while(!PathInfo.empty())
	{
		PathInfo.pop();
	}
	Parent.clear();
}

void Union(int Left, int Right)
{
	if (Left < Right)
	{
		Parent[Right] = Left;
	}
	else
	{
		Parent[Left] = Right;
	}
}

int	FindParent(int Node)
{
	if (Parent[Node] == Node)
	{
		return Node;
	}

	Parent[Node] = FindParent(Parent[Node]);
	return Parent[Node];
}


int Kruskal()
{
	int MSTCount = HouseCount - 1;
	int LinkCost = 0;

	while (MSTCount > 0 && !PathInfo.empty())
	{
		int LeftNode = PathInfo.top().second.first;
		int RightNode = PathInfo.top().second.second;
		int Cost = -PathInfo.top().first;

		PathInfo.pop();

		int LeftParent = FindParent(LeftNode);
		int RightParent = FindParent(RightNode);

		if (LeftParent != RightParent)
		{
			Union(LeftParent, RightParent);
			LinkCost += Cost;
			--MSTCount;
		}
	}

	return LinkCost;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::vector<int> Answer;

	while (true)
	{
		std::cin >> HouseCount >> PathCount;

		if (HouseCount == 0 && PathCount == 0)
		{
			break;
		}

		Init();
		Parent.resize(HouseCount, -1);
		for (int i = 0; i < HouseCount; i++)
		{
			Parent[i] = i;
		}

		int WholeCost = 0;

		for (int i = 0; i < PathCount; i++)
		{
			int LeftNode, RightNode, Cost;
			std::cin >> LeftNode >> RightNode;

			std::cin >> Cost;

			WholeCost += Cost;

			PathInfo.push(std::make_pair(-Cost, std::make_pair(LeftNode, RightNode)));
		}

		Answer.push_back(WholeCost - Kruskal());
	}

	for (auto i : Answer)
	{
		std::cout << i << '\n';
	}
	
	return 0;
}