//문제 주소 : https://www.acmicpc.net/problem/1937

#include <iostream>
#include <vector>

int N;
std::vector<std::vector<int>> Grid;
std::vector<std::vector<int>> DP;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int DFS(std::pair<int, int> CurNode)
{
	if (DP[CurNode.second][CurNode.first] != -1)
	{
		return DP[CurNode.second][CurNode.first];
	}

	DP[CurNode.second][CurNode.first] = 1;

	for (int i = 0; i < 4; i++)
	{
		int CheckX = CurNode.first + dx[i];
		int CheckY = CurNode.second + dy[i];

		if (CheckX < 0 || CheckY < 0 || CheckX >= N || CheckY >= N)
		{
			continue;
		}

		if (Grid[CurNode.second][CurNode.first] >= Grid[CheckY][CheckX])
		{
			continue;
		}

		DP[CurNode.second][CurNode.first] = std::max(DP[CurNode.second][CurNode.first], DFS(std::make_pair(CheckX, CheckY)) + 1);
	}

	return DP[CurNode.second][CurNode.first];
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	Grid.resize(N);
	DP.resize(N);
	for (int y = 0; y < N; y++)
	{
		Grid[y].resize(N);
		DP[y].resize(N, -1);
		for (int x = 0; x < N; x++)
		{
			std::cin >> Grid[y][x];
		}
	}
	
	int Answer = INT32_MIN;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			Answer = std::max(Answer, DFS({ x,y }));
		}
	}

	std::cout << Answer;

	return 0;
}