//문제 주소 : https://www.acmicpc.net/problem/1261

#include <iostream>
#include <vector>
#include <queue>

int Y, X;
std::vector<std::string> Grid;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

std::vector<std::vector<int>> Dijk(std::pair<int, int> StartNode)
{
	std::vector<std::vector<int>> Dist;
	Dist.resize(Y);
	for (int y = 0; y < Y; y++)
	{
		Dist[y].resize(X, INT32_MAX);
	}

	Dist[StartNode.second][StartNode.first] = 0;

	std::priority_queue<std::pair<int, std::pair<int, int>>> pq;
	pq.push(std::make_pair(-Dist[StartNode.second][StartNode.first], StartNode));

	while (!pq.empty())
	{
		int CurCost = -pq.top().first;
		std::pair<int, int> CurNode = pq.top().second;

		pq.pop();

		if (CurCost > Dist[CurNode.second][CurNode.first])
		{
			continue;
		}

		for (int i = 0; i < 4; i++)
		{
			int CheckX = CurNode.first + dx[i];
			int CheckY = CurNode.second + dy[i];

			if (CheckX < 0 || CheckY < 0 || CheckX >= X || CheckY >= Y)
			{
				continue;
			}

			int CheckCost = Grid[CheckY][CheckX] - '0';
			int ViaCost = CheckCost + CurCost;

			if (Dist[CheckY][CheckX] > ViaCost)
			{
				Dist[CheckY][CheckX] = ViaCost;
				pq.push(std::make_pair(-Dist[CheckY][CheckX], std::make_pair(CheckX, CheckY)));
			}
		}
	}

	return Dist;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	std::cin >> X >> Y;

	Grid.resize(Y);
	for (int y = 0; y < Y; y++)
	{
		Grid[y].resize(X);
		std::cin >> Grid[y];
	}

	std::cout << Dijk({ 0,0 })[Y - 1][X - 1];

	return 0;
}