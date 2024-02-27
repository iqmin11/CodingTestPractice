#include <iostream>
#include <vector>
#include <list>

int M, N;
std::vector<std::vector<int>> Grid;
std::vector<std::vector<bool>> DP;
std::vector<std::vector<bool>> IsVisit;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int PathCount = 0;

void DFS(std::pair<int, int> _CurPos)
{
	IsVisit[_CurPos.second][_CurPos.first];

	if (_CurPos.first == N - 1 && _CurPos.second == M - 1)
	{
		++PathCount;
		IsVisit[_CurPos.second][_CurPos.first] = false;

		return;
	}

	for (size_t i = 0; i < 4; i++)
	{
		int CheckX = _CurPos.first + dx[i];
		int CheckY = _CurPos.second + dy[i];

		if (CheckX < 0 || CheckY < 0 || CheckX >= N || CheckY >= M)
		{
			continue;
		}

		if (Grid[_CurPos.second][_CurPos.first] <= Grid[CheckY][CheckX])
		{
			continue;
		}

		DFS(std::make_pair(CheckX, CheckY));
	}

	IsVisit[_CurPos.second][_CurPos.first] = false;
}

int main()
{
	std::cin >> M >> N;
	
	Grid.resize(M);
	IsVisit.resize(M);
	DP.resize(M);
	for (size_t y = 0; y < M; y++)
	{
		Grid[y].resize(N);
		IsVisit[y].resize(N, false);
		DP[y].resize(N, false);
		for (size_t x = 0; x < N; x++)
		{
			std::cin >> Grid[y][x];
		}
	}

	DFS(std::make_pair(0,0));
	std::cout << PathCount;
}