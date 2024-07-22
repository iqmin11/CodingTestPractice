//문제 주소 : https://www.acmicpc.net/problem/12851

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
		//방문체크를 q에서 CurNode를 뺄때 체크하면, 서로 다른 경로에서 가는 방법들이 모두 q에 들어갈 수 있음
		//일반적으로 최단거리를 구할때는 CheckNode를 push할때 Visit Check를 하고, 그게 효율이 좋지만
		//이번 문제는 서로 다른경로에서 도착하는 경우가 몇가지 있는지 체크해야하기 때문에 이방법으로 해야함

		if (CurDepth > Answer.first) //Dest로 향하는 최단거리를 알았을 경우 더 깊은 노드를 검사할 필요 없음
		{
			return Answer;
		}
		
		if (CurNode == Dest) //q에 들어간 DestNode가 몇개인지 체크
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