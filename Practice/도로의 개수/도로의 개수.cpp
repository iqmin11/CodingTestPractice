//문제 주소 : https://www.acmicpc.net/problem/1577

#include <iostream>
#include <vector>
#include <queue>
#include <set>

int N, M, K;

std::vector<std::vector<uint64_t>> PathCount;
std::set<std::vector<int>> NoPassInfo;

int dx[] = { 1,0 };
int dy[] = { 0,1 };

void BFS(std::pair<int, int> StartNode)
{
	std::queue<std::pair<int, int>> q;
	PathCount[StartNode.second][StartNode.first] = 1;
	q.push(StartNode);

	while (!q.empty())
	{
		std::pair<int, int> CurNode = q.front();
		q.pop();

		for (int i = 0; i < 2; i++)
		{
			int CheckX = CurNode.first + dx[i];
			int CheckY = CurNode.second + dy[i];

			if (CheckX < 0 || CheckY < 0 || CheckX > N || CheckY > M)
			{
				continue;
			}

			int x1, y1, x2, y2;
			x1 = CurNode.first;
			x2 = CheckX;
			y1 = CurNode.second;
			y2 = CheckY;

			if (x1 > x2)
			{
				std::swap(x1, x2);
			}

			if (y1 > y2)
			{
				std::swap(y1, y2);
			}

			if (NoPassInfo.find(std::vector<int>({ x1, y1, x2, y2 })) != NoPassInfo.end())
			{
				continue;
			}

			if (PathCount[CheckY][CheckX] != 0)
			{
				PathCount[CheckY][CheckX] += PathCount[CurNode.second][CurNode.first];
				continue;
			}

			PathCount[CheckY][CheckX] += PathCount[CurNode.second][CurNode.first];
			q.push(std::make_pair(CheckX, CheckY));
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M >> K;

	for (int i = 0; i < K; i++)
	{
		int x1, y1, x2, y2;
		std::cin >> x1 >> y1 >> x2 >> y2;

		if (x1 > x2)
		{
			std::swap(x1, x2);
		}

		if (y1 > y2)
		{
			std::swap(y1, y2);
		}

		std::vector<int> temp = { x1, y1, x2, y2 };
		NoPassInfo.insert(std::move(temp));
	}

	PathCount.resize(M + 1);
	for (int i = 0; i <= M; i++)
	{
		PathCount[i].resize(N + 1, 0);
	}

	BFS({ 0,0 });

	std::cout << PathCount[M][N];

	return 0;
}