//문제 주소 : https://www.acmicpc.net/problem/13913

#include <iostream>
#include <queue>
#include <stack>

int S, E;
int IsVisit[100001];

void BFS()
{
	std::queue<int> q;
	for (int i = 0; i <= 100000; i++)
	{
		IsVisit[i] = -1;
	}
	IsVisit[S] = 100001;
	q.push(S);

	while (!q.empty())
	{
		int CurNode = q.front();
		q.pop();

		if (CurNode == E)
		{
			std::stack<int> Path;

			int PathFinder = CurNode;
			while (PathFinder != 100001)
			{
				Path.push(PathFinder);
				PathFinder = IsVisit[PathFinder];
			}

			std::cout << Path.size() - 1 << '\n';

			while (!Path.empty())
			{
				std::cout << Path.top() << ' ';
				Path.pop();
			}

			return;
		}

		for (int i = 0; i < 3; i++)
		{
			int CheckNode = CurNode;
			if (i == 0)
			{
				CheckNode += 1;
			}
			else if (i == 1)
			{
				CheckNode -= 1;
			}
			else
			{
				CheckNode *= 2;
			}

			if (CheckNode < 0 || CheckNode > 100000)
			{
				continue;
			}

			if (IsVisit[CheckNode] != -1)
			{
				continue;
			}

			q.push(CheckNode);
			IsVisit[CheckNode] = CurNode;
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> S >> E;

	if (S > E)
	{
		std::cout << S - E << '\n';
		for (int i = S; i >= E; --i)
		{
			std::cout << i << ' ';
		}
		return 0;
	}

	BFS();

	return 0;