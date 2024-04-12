//https://www.acmicpc.net/problem/1647

#include <iostream>
#include <vector>
#include <queue>

std::priority_queue<std::pair<int, std::pair<int, int>>> EdgeInfo; // -ºñ¿ë, ³ëµå½Ö
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

int MST(int N)
{
	int EdgeCount = 0;
	int MinValue = 0;
	while (!EdgeInfo.empty() && EdgeCount < N - 2)
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

			MinValue += CheckCost;
			++EdgeCount;
		}
	}

	return MinValue;
}

int main()
{
	int N, M;
	std::cin >> N >> M;

	Parent.resize(N);
	for (int i = 0; i < N; i++)
	{
		Parent[i] = i;
	}

	for (int i = 0; i < M; i++)
	{
		int Node1, Node2, Cost;
		std::cin >> Node1 >> Node2 >> Cost;
		EdgeInfo.push(std::make_pair(-Cost, std::make_pair(Node1 - 1, Node2 - 1)));
	}

	std::cout << MST(N);
}