//https://www.acmicpc.net/problem/17484

#include <iostream>
#include <vector>

int N, M;
std::vector<std::vector<int>> Grid;

int dx[] = { -1, 0 , 1 };
int dy[] = { 1, 1 , 1 };

int CurCost = 0;
int MinCost = INT32_MAX;

void DFS(std::pair<int, int> CurPos, int PrevDir = -1)
{
	CurCost += Grid[CurPos.second][CurPos.first];

	if (CurPos.second == N - 1)
	{
		MinCost = std::min(MinCost, CurCost);
		CurCost -= Grid[CurPos.second][CurPos.first];
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		if (PrevDir == i)
		{
			continue;
		}

		int CheckX = CurPos.first + dx[i];
		int CheckY = CurPos.second + dy[i];

		if (CheckX < 0 || CheckY < 0 || CheckX >= M || CheckY >= N)
		{
			continue;
		}

		DFS(std::make_pair(CheckX, CheckY), i);
	}

	CurCost -= Grid[CurPos.second][CurPos.first];
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;

	Grid.resize(N);
	for (int y = 0; y < N; y++)
	{
		Grid[y].resize(M);
		for (int x = 0; x < M; x++)
		{
			std::cin >> Grid[y][x];
		}
	}

	for (int x = 0; x < M; x++)
	{
		DFS(std::make_pair(x, 0));
	}

	std::cout << MinCost;
}