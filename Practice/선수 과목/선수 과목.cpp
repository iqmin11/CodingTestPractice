//문제 주소 : https://www.acmicpc.net/problem/14567

#include <iostream>
#include <vector>
#include <set>
#include <queue>

int N, M;
std::vector<int> InDegree;
std::vector<std::set<int>> LinkedNodes;

bool TopologySort(std::vector<int>& Result)
{
	std::queue<int> q; 
	Result.resize(N, 0);

	for (int i = 0; i < N; i++)
	{
		if (InDegree[i] == 0)
		{
			Result[i] = 1;
			q.push(i);
		}
	}

	for (int i = 0; i < N; i++)
	{
		if (q.empty())
		{
			return false;
		}

		int CurNode = q.front();
		q.pop();

		for (auto LinkNode : LinkedNodes[CurNode])
		{
			if (--InDegree[LinkNode] == 0)
			{
				q.push(LinkNode);
				Result[LinkNode] = Result[CurNode] + 1;
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

	std::cin >> N >> M;
	InDegree.resize(N, 0);
	LinkedNodes.resize(N);

	for (int i = 0; i < M; i++)
	{
		int From, To;
		std::cin >> From >> To;

		InDegree[To - 1]++;
		LinkedNodes[From - 1].insert(To - 1);
	}

	std::vector<int> Result;
	TopologySort(Result);

	for (int i = 0; i < Result.size(); i++)
	{
		std::cout << Result[i] << " ";
	}

	return 0;
}