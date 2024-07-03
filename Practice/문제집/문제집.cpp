//문제 주소 : https://www.acmicpc.net/problem/1766

#include <iostream>
#include <vector>
#include <set>
#include <queue>

int N, M;
std::vector<int> InDegree;
std::vector<std::set<int>> LinkedNodes;

bool TopologySort(std::vector<int>& Answer)
{
	std::priority_queue<int> pq;

	for (int i = 0; i < N; i++)
	{
		if (InDegree[i] == 0)
		{
			pq.push(-i);
		}
	}

	for (int i = 0; i < N; i++)
	{
		if (pq.empty())
		{
			return false;
		}

		int CurNode = -pq.top();
		pq.pop();

		Answer.push_back(CurNode + 1);

		for (auto LinkNode : LinkedNodes[CurNode])
		{
			if (--InDegree[LinkNode] == 0)
			{
				pq.push(-LinkNode);
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
		From--;
		To--;

		InDegree[To]++;
		LinkedNodes[From].insert(To);
	}

	std::vector<int> Answer;
	TopologySort(Answer);

	for (size_t i = 0; i < Answer.size(); i++)
	{
		std::cout << Answer[i] << " ";
	}

	return 0;
}