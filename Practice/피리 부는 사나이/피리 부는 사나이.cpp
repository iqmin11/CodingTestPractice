//문제 주소 : https://www.acmicpc.net/problem/16724

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

int Y, X;
std::vector<std::string> Grid;
std::vector<std::vector<int>> IsVisit;
std::set<int> Case;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int DFS(std::pair<int, int> CurNode, int CurCheck)
{
	IsVisit[CurNode.second][CurNode.first] = CurCheck;

	int Dir = 0;
	switch (Grid[CurNode.second][CurNode.first])
	{
	case 'U':
		Dir = 3;
		break;
	case 'D':
		Dir = 1;
		break;
	case 'L':
		Dir = 2;
		break;
	case 'R':
		Dir = 0;
		break;
	}

	int CheckX = CurNode.first + dx[Dir];
	int CheckY = CurNode.second + dy[Dir];

	if (IsVisit[CheckY][CheckX] != 0)
	{
		return IsVisit[CurNode.second][CurNode.first] = IsVisit[CheckY][CheckX];
	}

	return IsVisit[CurNode.second][CurNode.first] = DFS(std::make_pair(CheckX, CheckY), CurCheck);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> Y >> X;

	Grid.resize(Y);
	IsVisit.resize(Y);
	for (int y = 0; y < Y; y++)
	{
		std::cin >> Grid[y];
		IsVisit[y].resize(X, false);
	}

	int PrevCheck = 1;
	int CurCheck = 1;

	for (int y = 0; y < Y; y++)
	{
		for (int x = 0; x < X; x++)
		{
			if (IsVisit[y][x] != 0)
			{
				continue;
			}

			Case.insert(DFS({ x,y }, CurCheck++));
		}
	}

	std::cout << Case.size();

	return 0;
}