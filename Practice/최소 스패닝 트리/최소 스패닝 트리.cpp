//https://www.acmicpc.net/problem/1197

#include <iostream>
#include <queue>

int V, E;

std::priority_queue<std::pair<int, std::pair<int, int>>> EdgeInfo;
std::vector<int> Parent;

int FindParent(int Value) 
{
	if (Parent[Value] == Value)
	{
		return Value;
	}
	Parent[Value] = FindParent(Parent[Value]);
	return Parent[Value];
}

void Union(int FirstParent, int SecondParent) 
{
	if (FirstParent < SecondParent) 
	{
		Parent[SecondParent] = FirstParent;
	}
	else
	{
		Parent[FirstParent] = SecondParent;
	}
}

int MST_Kruskal(int N) 
{
	int EdgeCount = 0;
	int SumOfCost = 0;

	while (!EdgeInfo.empty() && EdgeCount < N - 1)
	{
		int CheckCost = -EdgeInfo.top().first;
		int FirstNode = EdgeInfo.top().second.first;
		int SecondNode = EdgeInfo.top().second.second;
		EdgeInfo.pop();

		int FirstParent = FindParent(FirstNode);
		int SecondParent = FindParent(SecondNode);
		if (FirstParent != SecondParent) 
		{
			Union(FirstParent, SecondParent);
			SumOfCost += CheckCost;
			++EdgeCount;
		}
	}

	return SumOfCost;
}

int main()
{
	std::cin >> V >> E;
	Parent.resize(V);

	for (size_t i = 0; i < V; i++)
	{
		Parent[i] = i;
	}

	for (int i = 0; i < E; i++)
	{
		int Vertex1;
		int Vertex2;
		int Cost;

		std::cin >> Vertex1 >> Vertex2 >> Cost;
		EdgeInfo.push(std::make_pair(-Cost, std::make_pair(Vertex1 - 1, Vertex2 - 1)));
	}

	std::cout << MST_Kruskal(V);

	return 0;
}