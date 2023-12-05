#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>

std::vector<int> InDegree;
std::vector<int> Costs;
std::vector<std::set<int>> LinkNodes;
std::vector<std::set<int>> InDgreeNodes;

int TopologySort()
{
	std::priority_queue<std::pair<int, int>> pq;
	int result = INT32_MIN;
	std::vector<int> DPCost = Costs;

	for (int i = 0; i < InDegree.size(); i++)
	{
		if (InDegree[i] == 0)
		{
			pq.push({ -Costs[i], i });
		}
	}

	for (int i = 0; i < InDegree.size(); i++)
	{
		if (pq.empty())
		{
			return -1;
		}

		int CheckCost = -pq.top().first;
		int CheckIndex = pq.top().second;
		pq.pop();
		result = std::max(result, CheckCost);

		for (auto& LinkNode : LinkNodes[CheckIndex])
		{
			if (--InDegree[LinkNode] == 0)
			{
				pq.push({ -(Costs[LinkNode] + result), LinkNode });
			}
		}
	}

	return result;
}

int main()
{
	int N;
	std::cin >> N;

	InDegree.resize(N);
	LinkNodes.resize(N);
	Costs.resize(N);
	InDgreeNodes.resize(N);

	for (int To = 0; To < N; To++)
	{
		int Cost, Deg;
		std::cin >> Cost;
		std::cin >> Deg;
		InDegree[To] = Deg;
		Costs[To] = Cost;

		for (int j = 0;  j < Deg;  j++)
		{
			int from;
			std::cin >> from;
			LinkNodes[from-1].insert(To);
			InDgreeNodes[To].insert(from - 1);
		}
	}
	
	int AllCost = TopologySort();

	std::cout << AllCost;
}