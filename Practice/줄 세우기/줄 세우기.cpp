#include <iostream>
#include <vector>
#include <set>
#include <queue>

std::vector<int> InDegree;
std::vector<std::set<int>> LinkNodes;

void TopologySort()
{
	std::queue<int> q;
	int N = InDegree.size();

	for (size_t i = 0; i < N; i++)
	{
		if (InDegree[i] == 0)
		{
			q.push(i);
		}
	}

	for (size_t i = 0; i < N; i++)
	{
		if (q.empty())
		{
			return;
		}

		int Check = q.front();
		q.pop();
		std::cout << Check + 1 << " ";

		for (auto& LinkNode : LinkNodes[Check])
		{
			if (--InDegree[LinkNode] == 0)
			{
				q.push(LinkNode);
			}
		}
	}
}

int main()
{
	int N, M;
	std::cin >> N >> M;

	InDegree.resize(N);
	LinkNodes.resize(N);


	for (size_t i = 0; i < M; i++)
	{
		int A, B;
		std::cin >> A >> B;
		InDegree[B-1]++;
		LinkNodes[A-1].insert(B-1);
	}

	TopologySort();

	return 0;
}