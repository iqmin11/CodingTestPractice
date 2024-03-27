//https://www.acmicpc.net/problem/16398

#include <iostream>
#include <vector>
#include <queue>

std::priority_queue<std::pair<long long, std::pair<int, int>>> EdgeInfo; //Cost, 연결 노드 정보
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

int main()
{
	int N;

	std::cin >> N;
	Parent.resize(N);

	for (int i = 0; i < N; i++)
	{
		Parent[i] = i;
		for (int j = 0; j < N; j++)
		{
			long long Cost;
			std::cin >> Cost;
			if (i <= j)
			{
				continue;
			}
			EdgeInfo.push(std::make_pair(-Cost, std::make_pair(i, j)));
		}
	}

	long long Answer = 0;
	int EdgeCount = 0;

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
			Answer += CheckCost;
			++EdgeCount;
		}
	}

	std::cout << Answer;
}