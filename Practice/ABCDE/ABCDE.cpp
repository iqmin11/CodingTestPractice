//문제 주소 : https://www.acmicpc.net/problem/13023

#include <iostream>
#include <vector>

int N, M;
std::vector<bool> IsVisit;
std::vector<std::vector<int>> LinkNodes;

int PathLength = 0;
int Answer = false;
void DFS(int CurNode)
{
	if (Answer)
	{
		return;
	}	

	IsVisit[CurNode] = true;
	PathLength++;

	if (PathLength == 5)
	{
		Answer = true;
		return;
	}

	for (auto LinkNode : LinkNodes[CurNode])
	{
		if (IsVisit[LinkNode])
		{
			continue;
		}

		DFS(LinkNode);
	}

	IsVisit[CurNode] = false;
	PathLength--;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;
	
	IsVisit.resize(N, false);
	LinkNodes.resize(N);
	for (int i = 0; i < N; i++)
	{
		LinkNodes[i].reserve(N);
	}

	for (size_t i = 0; i < M; i++)
	{
		int Node1, Node2;
		std::cin >> Node1 >> Node2;
		LinkNodes[Node1].push_back(Node2);
		LinkNodes[Node2].push_back(Node1);
	}

	for (int i = 0; i < N; i++)
	{
		if (Answer)
		{
			break;
		}

		
		for (int j = 0; j < N; j++)
		{
			IsVisit[j] = false;
		}

		DFS(i);
	}

	std::cout << Answer;

	return 0;
}