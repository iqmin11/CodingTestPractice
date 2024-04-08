//https://school.programmers.co.kr/learn/courses/30/lessons/42861

#include <string>
#include <vector>
#include <queue>

using namespace std;

std::priority_queue<std::pair<long long, std::pair<int, int>>> EdgeInfo;
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

int MST(int N) //간선의 개수
{
	int EdgeCount = 0;
	int MinCost = 0;
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
			MinCost += CheckCost;
			++EdgeCount;
		}
	}

	return MinCost;
}

int solution(int n, vector<vector<int>> costs)
{
	Parent.resize(n);
	for (int i = 0; i < n; ++i)
	{
		Parent[i] = i;
	}

	for (int i = 0; i < costs.size(); ++i)
	{
		int Node1 = costs[i][0];
		int Node2 = costs[i][1];
		int Cost = costs[i][2];

		EdgeInfo.push(std::make_pair(-Cost, std::make_pair(Node1, Node2)));
	}

	int answer = MST(n);
	return answer;
}