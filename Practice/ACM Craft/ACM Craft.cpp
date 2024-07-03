//문제 주소 : https://www.acmicpc.net/problem/1005

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <numeric>

bool TopologySort
(
	std::vector<int>& Result,
	std::vector<int>& InDegree,
	std::vector<std::set<int>>& LinkNodes,
	const std::vector<int>& TimeInfo
)
{
	std::queue<int> q;
	Result = TimeInfo;

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
			return false;
		}

		int CurIndex = q.front();
		q.pop();

		for (auto LinkNode : LinkNodes[CurIndex])
		{
			Result[LinkNode] = std::max(Result[LinkNode], Result[CurIndex] + TimeInfo[LinkNode]);
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
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int T;
	std::cin >> T;

	while (T-- != 0)
	{
		int N, K;
		std::cin >> N >> K;

		std::vector<int> InDegree;
		InDegree.resize(N);

		std::vector<std::set<int>> LinkedNodes;
		LinkedNodes.resize(N);

		std::vector<int> ConstructTime;
		ConstructTime.resize(N);

		for (int i = 0; i < N; ++i)
		{
			std::cin >> ConstructTime[i];
		}

		for (int i = 0; i < K; ++i)
		{
			int From, To;
			std::cin >> From >> To;

			--From;
			--To;
			++InDegree[To];
			LinkedNodes[From].insert(To);
		}

		std::vector<int> Result;
		int W;
		std::cin >> W;

		if (TopologySort(Result, InDegree, LinkedNodes, ConstructTime))
		{
			std::cout << Result[W - 1] << std::endl;
		}
	}

	return 0;
}