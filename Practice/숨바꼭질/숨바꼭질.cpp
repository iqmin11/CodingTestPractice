//문제 주소 : https://www.acmicpc.net/problem/1697

#include <iostream>
#include <queue>
#include <unordered_set>

std::unordered_set<int> IsVisit;

int BFS(int S, int E)
{
	std::queue<std::pair<int, int>> q;
	IsVisit.insert(S);
	q.push(std::make_pair(S, 0));

	while (!q.empty())
	{
		int CurPos = q.front().first;
		int CurDepth = q.front().second;
		q.pop();

		if (CurPos == E)
		{
			return CurDepth;
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
			else if (i == 2)
			{
				CheckPos *= 2;
			}

			if (CheckPos < 0 || CheckPos > 100000)
			{
				continue;
			}

			if (IsVisit.find(CheckPos) != IsVisit.end())
			{
				continue;
			}

			q.push(std::make_pair(CheckPos, CurDepth + 1));
			IsVisit.insert(CheckPos);
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
	std::cout << BFS(S, E);

	return 0;
}