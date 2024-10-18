//���� �ּ� : https://www.acmicpc.net/problem/13549

#include <iostream>
#include <queue>

bool IsVisit[100001] = {0,};

void BFS(int StartPos, int DestPos)
{
	//-����, ��ġ
	std::priority_queue<std::pair<int, int>> pq;
	pq.push(std::make_pair(0, StartPos));

	while (!pq.empty())
	{
		int CurPos = pq.top().second;
		int CurDepth = -pq.top().first;
		pq.pop();

		if (IsVisit[CurPos] == true)
		{
			continue;
		}

		IsVisit[CurPos] = true;

		if (CurPos == DestPos)
		{
			std::cout << CurDepth;
			return;
		}

		for (int i = 0; i < 3; i++)
		{
			int CheckPos = CurPos;

			if (i == 0)
			{
				CheckPos += 1;
			}
			else if (i == 1)
			{
				CheckPos -= 1;
			}
			else
			{
				CheckPos *= 2;
			}

			if (CheckPos < 0 || CheckPos > 100000)
			{
				continue;
			}

			//if (IsVisit[CheckPos]) //�������� ������ �� ����. �ֳ��ϸ� ���̰��� ���߿� �湮�� ���� ���� üũ�� �� �� �ֱ� ����
			//{
			//	//�湮üũ�� �ƿ� ť���� ���� �ϴ°� ����� �� �� ����.
			//	continue;
			//}

			int CheckDepth = CurDepth;
			if (i == 0 || i == 1)
			{
				CheckDepth += 1;
			}
		
			//IsVisit[CheckPos] = true;
			pq.push(std::make_pair(-CheckDepth, CheckPos));
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int S, E;
	std::cin >> S >> E;

	BFS(S, E);

	return 0;
}