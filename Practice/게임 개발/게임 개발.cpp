#include <iostream>
#include <vector>
#include <set>
#include <queue>


std::vector<int> InDegree; //degree, cost
std::vector<std::set<int>> InDegreeNodes;
std::vector<int> BuildCost; //degree, cost
std::vector<std::set<int>> LinkNodes;

bool TopologySort(std::vector<int>& _result)
{
	std::queue<int> q;
	std::vector<int>& result = _result; // result[a] a건물을 짓는데 드는 최소 비용
	result = BuildCost;

	for (int i = 0; i < InDegree.size(); i++)
	{
		if (InDegree[i] == 0)
		{
			q.push(i);
		}
	}

	for (int i = 0; i < InDegree.size(); i++)
	{
		if (q.empty())
		{
			result.clear();
			return false;
		}

		int Check = q.front();
		q.pop();

		for (auto& LinkNode : LinkNodes[Check])
		{
			int MaxCost = INT32_MIN;
			for (auto& InDeNode : InDegreeNodes[LinkNode])
			{
				MaxCost = std::max(result[InDeNode], MaxCost); //DP느낌, 직전에 지은 건물 중 최대비용 + 현재 건물 짓는 비용
			}

			result[LinkNode] = MaxCost + BuildCost[LinkNode];
			if (--InDegree[LinkNode] == 0)
			{
				q.push(LinkNode);
			}
		}
	}

	return true;
}

int main()
{
	int N;
	std::cin >> N;

	InDegree.reserve(N);
	LinkNodes.resize(N);
	InDegreeNodes.resize(N);

	for (int i = 0; i < N; i++)
	{
		int Cost;
		std::cin >> Cost;

		int Check = 0;
		int Count = 0;

		while (true)
		{
			std::cin >> Check;
			if (Check == -1)
			{
				break;
			}
			Count++;
			LinkNodes[Check - 1].insert(i);
			InDegreeNodes[i].insert(Check - 1);
		}

		InDegree.emplace_back(Count);
		BuildCost.emplace_back(Cost);
	}

	std::vector<int> Result;
	if (TopologySort(Result))
	{
		for (size_t i = 0; i < Result.size(); i++)
		{
			std::cout << Result[i] << '\n';
		}
	};

	return 0;
}