//문제 주소 : https://www.acmicpc.net/problem/1890

#include <iostream>
#include <vector>

int N;
std::vector<std::vector<int>> Grid;
std::vector<std::vector<uint64_t>> DP; // DP[y][x] = (x, y) 에서 (n -1, n - 1)까지 가는 경로의 개수

int dx[] = { 1, 0 };
int dy[] = { 0, 1 };

std::pair<int, int> Dest;

void DebugRender(const std::vector<std::vector<uint64_t>>& GridArr)
{
	std::cout << "/////////////////////////////////" << std::endl;

	for (size_t y = 0; y < GridArr.size(); y++)
	{
		for (size_t x = 0; x < GridArr[y].size(); x++)
		{
			std::cout << DP[y][x] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "/////////////////////////////////" << std::endl;
}

uint64_t DFS(std::pair<int, int> CurNode)
{
	if (Dest == CurNode)
	{
		return 1;
	}

	if (DP[CurNode.second][CurNode.first] != -1)
	{
		return DP[CurNode.second][CurNode.first];
	}

	DP[CurNode.second][CurNode.first] = 0;

	for (int Dir = 0; Dir < 2; Dir++)
	{
		int CheckX = CurNode.first + dx[Dir] * Grid[CurNode.second][CurNode.first];
		int CheckY = CurNode.second + dy[Dir] * Grid[CurNode.second][CurNode.first];

		if (CheckX >= N || CheckY >= N)
		{
			continue;
		}

		DP[CurNode.second][CurNode.first] = DP[CurNode.second][CurNode.first] + DFS(std::make_pair(CheckX, CheckY));
	}
	
	return DP[CurNode.second][CurNode.first];
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	Dest = { N - 1, N - 1 };
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

	std::cout << DFS({ 0,0 });

	return 0;
}