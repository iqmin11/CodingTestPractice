//문제 주소 : https://www.acmicpc.net/problem/1189

#include <iostream>
#include <vector>

int R, C, K;
std::vector<std::vector<char>> Grid;
std::vector<std::vector<bool>> IsVisit;

std::pair<int, int> Start;
std::pair<int, int> Dest;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int Answer = 0;
int CurPahtLength = 0;

void DFS(std::pair<int, int> CurPos)
{
	if (CurPahtLength > K)
	{
		return;
	}

	IsVisit[CurPos.second][CurPos.first] = true;
	CurPahtLength++;

	if (CurPos == Dest && CurPahtLength == K)
	{
		IsVisit[CurPos.second][CurPos.first] = false;
		CurPahtLength--;
		Answer++;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int CheckX = CurPos.first + dx[i];
		int CheckY = CurPos.second + dy[i];

		if (CheckX < 0 || CheckY < 0 || CheckX >= C || CheckY >= R)
		{
			continue;
		}

		if (IsVisit[CheckY][CheckX])
		{
			continue;
		}

		if (Grid[CheckY][CheckX] == 'T')
		{
			continue;
		}

		DFS(std::make_pair(CheckX, CheckY));
	}

	IsVisit[CurPos.second][CurPos.first] = false;
	CurPahtLength--;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> R >> C >> K;
	Grid.resize(R);
	IsVisit.resize(R);

	for (int y = 0; y < R; y++)
	{
		Grid[y].resize(C);
		IsVisit[y].resize(C, false);

		for (int x = 0; x < C; x++)
		{
			std::cin >> Grid[y][x];
		}
	}

	Start = std::make_pair(0, R - 1);
	Dest = std::make_pair(C - 1, 0);

	DFS(Start);
	std::cout << Answer;

	return 0;
}