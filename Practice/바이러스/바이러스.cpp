//문제 주소 : https://www.acmicpc.net/problem/2606

#include <iostream>
#include <vector>
#include <queue>

int N, M;

std::vector<std::vector<int>> LinkedInfo;
std::vector<bool> IsVisit;
int Answer = 0;

void DFS(int CurNode)
{
	IsVisit[CurNode] = true;
	Answer++;

	for (auto LinkNode : LinkedInfo[CurNode])
	{
		if (IsVisit[LinkNode])
		{
			continue;
		}

		DFS(LinkNode);
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;
	LinkedInfo.resize(N);
	IsVisit.resize(N, false);

	for (int i = 0; i < M; i++)
	{
		int v0, v1;
		std::cin >> v0 >> v1;
		--v0;
		--v1;
		LinkedInfo[v0].push_back(v1);
		LinkedInfo[v1].push_back(v0);
	}

	DFS(0);
	std::cout << Answer - 1;

	return 0;
}