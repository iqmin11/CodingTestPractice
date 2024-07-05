//문제 주소 : https://www.acmicpc.net/problem/2098

#include <iostream>
#include <vector>

int N;
std::vector<std::vector<int>> Cost; //Cost[a][b] -> a에서 b로 가는 비용
std::vector<std::vector<int>> DP; //DP[i][Visited] 현재 위치 i, 방문 상황 Visited
int AllVisit = 1;

int DFS(int CurNode, int VisitedBit)
{
	if (VisitedBit == AllVisit)
	{
		if (Cost[CurNode][0] == 0)
		{
			return 987654321;
		}
		else
		{
			return Cost[CurNode][0];
		}
	}

	if (DP[CurNode][VisitedBit] != -1)
	{
		return DP[CurNode][VisitedBit];
	}
	
	DP[CurNode][VisitedBit] = 987654321;

	for (int CheckNode = 0; CheckNode < N; CheckNode++)
	{
		if (Cost[CurNode][CheckNode] == 0)
		{
			continue;
		}

		if (VisitedBit >> CheckNode & 1)
		{
			continue;
		}

		DP[CurNode][VisitedBit] = std::min(DP[CurNode][VisitedBit], Cost[CurNode][CheckNode] + DFS(CheckNode, VisitedBit | (1 << CheckNode)));
	}

	return DP[CurNode][VisitedBit];
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	
	Cost.resize(N);
	for (int y = 0; y < N; y++)
	{
		Cost[y].resize(N);
		for (int x = 0; x < N; x++)
		{
			std::cin >> Cost[y][x];
		}
	}

	DP.resize(N);
	unsigned int Bit = 1 << N;
	for (int i = 0; i < N; i++)
	{
		DP[i].resize(Bit, -1);
	}

	AllVisit = (AllVisit << N) - 1;

	std::cout << DFS(0, 1);

	return 0;
}