//문제 주소 : https://www.acmicpc.net/problem/11725

#include <iostream>
#include <vector>

int N;
std::vector<std::vector<int>> LinkedInfo;
std::vector<bool> IsVisit;
std::vector<int> ParentInfo;

void DFS(int CurNode)
{
	IsVisit[CurNode] = true;

	for (auto LinkNode : LinkedInfo[CurNode])
	{
		if (IsVisit[LinkNode])
		{
			continue;
		}

		ParentInfo[LinkNode] = CurNode;
		DFS(LinkNode);
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	LinkedInfo.resize(N + 1);
	IsVisit.resize(N + 1, false);
	ParentInfo.resize(N + 1, -1);

	for (int i = 0; i < N - 1; i++)
	{
		int Node0, Node1;
		std::cin >> Node0 >> Node1;

		LinkedInfo[Node0].push_back(Node1);
		LinkedInfo[Node1].push_back(Node0);
	}

	DFS(1);
	
	for (int i = 2; i <= N; i++)
	{
		std::cout << ParentInfo[i] << '\n';
	}

	return 0;
}