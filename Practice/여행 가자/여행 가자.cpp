//문제 주소 : https://www.acmicpc.net/problem/1976

#include <iostream>
#include <vector>
#include <set>

int N, M;

std::vector<bool> IsVisit;
std::vector<std::set<int>> LinkNodes;

void DFS(int CurNode)
{
	IsVisit[CurNode] = true;

	for (auto& NextNode : LinkNodes[CurNode])
	{
		if (IsVisit[NextNode])
		{
			continue;
		}

		DFS(NextNode);
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;

	LinkNodes.resize(N);
	IsVisit.resize(N, false);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			bool IsLinked;
			std::cin >> IsLinked;

			if (IsLinked)
			{
				LinkNodes[i].insert(j);
				LinkNodes[j].insert(i);
			}
		}
	}

	std::vector<int> Path;
	Path.reserve(M);

	for (int i = 0; i < M; i++)
	{
		int temp;
		std::cin >> temp;
		Path.push_back(temp - 1);
	}

	DFS(Path[0]);

	bool Answer = true;

	for (int i = 0; i < M; i++)
	{
		if (IsVisit[Path[i]])
		{
			continue;
		}

		Answer = false;
		break;
	}

	if (Answer)
	{
		std::cout << "YES";
	}
	else
	{
		std::cout << "NO";
	}

	return 0;
}