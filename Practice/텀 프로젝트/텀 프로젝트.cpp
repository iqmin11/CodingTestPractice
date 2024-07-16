//문제 주소 : https://www.acmicpc.net/problem/9466

#include <iostream>
#include <vector>

void DFS(int CurNode, const std::vector<int>& Link, std::vector<bool>& IsVisit, int& StartNode, int& Result, bool& IsCir)
{
	if (IsVisit[CurNode])
	{
		//VisitCheck가 되어있는 순간 StartNode 갱신
		StartNode = CurNode;
		return;
	}
	
	IsVisit[CurNode] = true;

	int CheckNode = Link[CurNode];

	DFS(CheckNode, Link, IsVisit, StartNode, Result, IsCir);

	if (!IsCir) //순환 확인을 한 순간부터는 Count 세기를 멈춤
	{
		++Result;
	}

	if (StartNode == CurNode)
	{
		//빠져나가면서 체크
		IsCir = true;
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int T;
	std::cin >> T;
	std::vector<int> LinkNodes;
	std::vector<bool> IsVisit;

	for (int t = 0; t < T; t++)
	{
		int N;
		std::cin >> N;

		LinkNodes.clear();
		LinkNodes.resize(N + 1);
		
		IsVisit.clear();
		IsVisit.resize(N + 1, false);

		for (int i = 1; i <= N; i++)
		{
			std::cin >> LinkNodes[i];
		}

		int Answer = N;

		for (int i = 1; i <= N; i++)
		{
			if (IsVisit[i])
			{
				continue;
			}

			bool IsCir = false; //순환을 찾아냈는지에 대한 Boolean
			int Result = 0; //순환을 찾았을 경우, 순환하는 노드의 갯수
			int StartNode = -1; //DFS 경로상 마지막 다음 노드, DFS를 빠져나오면서 해당 노드를 만난적이 있는지 체크
			DFS(i, LinkNodes, IsVisit, StartNode, Result, IsCir);

			if (IsCir)
			{
				Answer -= Result;
			}
		}

		std::cout << Answer << '\n';
	}

	return 0;
}