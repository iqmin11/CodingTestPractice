//���� �ּ� : https://www.acmicpc.net/problem/12851

#include <iostream>
#include <queue>
#include <vector>
#include <functional>

std::vector<std::function<int(int)>> FuncTable;
bool IsVisit[100001];

std::pair<int, int> BFS(int Start, int Dest)
{
	std::pair<int, int> Answer = { INT32_MAX, 0};
	
	std::queue<std::pair<int, int>> q;
	q.push(std::make_pair(Start, 0));

	while (!q.empty())
	{
		int CurNode = q.front().first;
		int CurDepth = q.front().second;
		q.pop();

		IsVisit[CurNode] = true;
		//�湮üũ�� q���� CurNode�� ���� üũ�ϸ�, ���� �ٸ� ��ο��� ���� ������� ��� q�� �� �� ����
		//�Ϲ������� �ִܰŸ��� ���Ҷ��� CheckNode�� push�Ҷ� Visit Check�� �ϰ�, �װ� ȿ���� ������
		//�̹� ������ ���� �ٸ���ο��� �����ϴ� ��찡 ��� �ִ��� üũ�ؾ��ϱ� ������ �̹������ �ؾ���

		if (CurDepth > Answer.first) //Dest�� ���ϴ� �ִܰŸ��� �˾��� ��� �� ���� ��带 �˻��� �ʿ� ����
		{
			return Answer;
		}
		
		if (CurNode == Dest) //q�� �� DestNode�� ����� üũ
		{
			Answer.first = CurDepth;
			Answer.second++;
			continue;
		}

		for (int i = 0; i < 3; i++)
		{
			int CheckNode = FuncTable[i](CurNode);

			if (CheckNode < 0 || CheckNode > 100000)
			{
				continue;
			}

			if (IsVisit[CheckNode])
			{
				continue;
			}

			q.push(std::make_pair(CheckNode, CurDepth + 1));
		}
	}

	return Answer;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	FuncTable.push_back([](int CurNode)
		{
			int LinkNode = CurNode + 1;
			return LinkNode;
		});

	FuncTable.push_back([](int CurNode)
		{
			int LinkNode = CurNode - 1;
			return LinkNode;
		});

	FuncTable.push_back([](int CurNode)
		{
			int LinkNode = CurNode * 2;
			return LinkNode;
		});

	int Start, Dest;

	std::cin >> Start >> Dest;

	std::pair<int, int> Answer = BFS(Start, Dest);
	std::cout << Answer.first << '\n' << Answer.second;

	return 0;
}