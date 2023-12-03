#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>

std::vector<std::pair<int, int>> InDegree;
std::vector<std::set<int>> LinkNodes;

int TopologySort()
{
	std::queue<int> q;
	int result = 0;
	std::vector<int> Depth;
	Depth.resize(InDegree.size(), INT32_MAX);

	for (int i = 0; i < InDegree.size(); i++)
	{
		if (InDegree[i].second == 0)
		{
			q.push(i);
			Depth[i] = 0;
		}
	}

	for (int i = 0; i < InDegree.size(); i++)
	{
		if (q.empty())
		{
			return -1;
		}

		int CheckIndex = q.front();
		q.pop();

		for (auto& LinkNode : LinkNodes[CheckIndex])
		{
			if (--InDegree[LinkNode].second == 0)
			{
				Depth[LinkNode] = Depth[CheckIndex] + 1;
				q.push(LinkNode);
			}
		}
	}

	std::map<int, int> DP;

	for (size_t i = 0; i < Depth.size(); i++)
	{
		if (DP.find(Depth[i]) == DP.end())
		{
			DP[Depth[i]] = InDegree[i].first;
		}
		else
		{
			DP[Depth[i]] = std::max(InDegree[i].first, DP[Depth[i]]);
		}
	}

	for (auto& i : DP)
	{
		result += i.second;
	}

	return result;
}

int main()
{
	int N;
	std::cin >> N;

	InDegree.resize(N);
	LinkNodes.resize(N);

	for (int To = 0; To < N; To++)
	{
		int Cost, Deg;
		std::cin >> Cost;
		std::cin >> Deg;
		InDegree[To] = { Cost , Deg };

		for (int j = 0;  j < Deg;  j++)
		{
			int from;
			std::cin >> from;
			LinkNodes[from-1].insert(To);
		}
	}
	
	int AllCost = TopologySort();

	std::cout << AllCost;
}