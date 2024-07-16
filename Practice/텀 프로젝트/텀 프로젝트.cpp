//���� �ּ� : https://www.acmicpc.net/problem/9466

#include <iostream>
#include <vector>

void DFS(int CurNode, const std::vector<int>& Link, std::vector<bool>& IsVisit, int& StartNode, int& Result, bool& IsCir)
{
	if (IsVisit[CurNode])
	{
		//VisitCheck�� �Ǿ��ִ� ���� StartNode ����
		StartNode = CurNode;
		return;
	}
	
	IsVisit[CurNode] = true;

	int CheckNode = Link[CurNode];

	DFS(CheckNode, Link, IsVisit, StartNode, Result, IsCir);

	if (!IsCir) //��ȯ Ȯ���� �� �������ʹ� Count ���⸦ ����
	{
		++Result;
	}

	if (StartNode == CurNode)
	{
		//���������鼭 üũ
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

			bool IsCir = false; //��ȯ�� ã�Ƴ´����� ���� Boolean
			int Result = 0; //��ȯ�� ã���� ���, ��ȯ�ϴ� ����� ����
			int StartNode = -1; //DFS ��λ� ������ ���� ���, DFS�� ���������鼭 �ش� ��带 �������� �ִ��� üũ
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