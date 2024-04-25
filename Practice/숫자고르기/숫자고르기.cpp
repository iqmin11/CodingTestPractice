//문제 주소 : https://www.acmicpc.net/problem/2668

#include <iostream>
#include <vector>

int N;
std::vector<int> LinkNode;
std::vector<bool> IsVisit;
std::vector<bool> VisitCheckInit;

bool DFS(int CurNode, int StartNode)
{
	IsVisit[CurNode] = true;

	int NextNode = LinkNode[CurNode];

	if (NextNode == StartNode)
	{
		return true;
	}

	if (!IsVisit[NextNode])
	{
		return DFS(NextNode, StartNode);
	}

	return false;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	LinkNode.resize(N, 0);
	IsVisit.resize(N, false);
	VisitCheckInit.resize(N, false);

	for (int i = 0; i < N; i++)
	{
		std::cin >> LinkNode[i];
		--LinkNode[i];
	}

	std::vector<int> Answer;

	for (int i = 0; i < N; i++)
	{
		IsVisit = VisitCheckInit;
		bool IsCycle = DFS(i, i);
		if (IsCycle)
		{
			Answer.push_back(i + 1);
		}
	}

	std::cout << Answer.size() << '\n';

	for (int i = 0; i < Answer.size(); i++)
	{
		std::cout << Answer[i] << '\n';
	}

	return 0;
}