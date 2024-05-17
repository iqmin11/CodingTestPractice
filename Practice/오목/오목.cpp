//문제 주소 : https://www.acmicpc.net/problem/2615

#include <iostream>
#include <vector>
#include <set>

std::vector<std::vector<int>> Grid;
std::vector<std::vector<std::vector<bool>>> IsVisit;

//왼쪽부터 검사를해야됐기 때문에 set으로 정렬
std::set<std::pair<int, int>> BlackPos;
std::set<std::pair<int, int>> WhitePos;

//왼쪽에서 오른쪽으로 탐색 방향을 고려
//이렇게 하면 시작 지점이 항상 가장 왼쪽이 됨
int dx[] = { 0, 1, 1, 1 };
int dy[] = { 1, 1, 0, -1 };

int Depth = 0;
bool IsWin[3] = {false, false, false};
void DFS(std::pair<int, int> CurPos, int CheckColor, int PrevDir = -1)
{
	//바둑돌의 시작지점에선 네방향을 다 체크할 것이기 때문에 네방향을 다 true로 방문체크함
	if (PrevDir == -1)
	{
		for (int i = 0; i < 4; i++)
		{
			IsVisit[CurPos.second][CurPos.first][i] = true;
		}
	}
	else
	{
		IsVisit[CurPos.second][CurPos.first][PrevDir] = true;
	}

	Depth++;

	bool IsEnd = true;

	for (int Dir = 0; Dir < 4; Dir++)
	{
		if(PrevDir != -1) //시작점이면 네방향 다 체크 해야함
		{
			if (PrevDir != Dir) //시작점이 아니면 같은 방향만 체크
			{
				continue;
			}
		}

		int CheckX = CurPos.first + dx[Dir];
		int CheckY = CurPos.second + dy[Dir];

		if (CheckX < 0 || CheckY < 0 || CheckX >= 19 || CheckY >= 19)
		{
			continue;
		}

		if (IsVisit[CheckY][CheckX][Dir]) //방향을 고려한 방문체크
		{
			continue;
		}

		if (Grid[CheckY][CheckX] != CheckColor)
		{
			continue;
		}

		//돌곳이 있으니 끝부분이 아니야
		IsEnd = false;
		DFS(std::make_pair(CheckX, CheckY), CheckColor, Dir);
	}

	if (IsEnd) //더 돌 곳이 없다면 탐색한 길의 가장 끝 부분이라는 뜻
	{
		if (Depth == 5) // 그때의 깊이가 5라면
		{
			IsWin[CheckColor] = true; //이겼다
		}
	}

	Depth--;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	Grid.resize(19);
	IsVisit.resize(19);
	for (int y = 0; y < 19; y++)
	{
		Grid[y].resize(19, 0);
		IsVisit[y].resize(19);
		for (int x = 0; x < 19; x++)
		{
			//방향을 고려한 방문체크(4방향)
			IsVisit[y][x].resize(4, false);
			std::cin >> Grid[y][x];
			if (Grid[y][x] == 1)
			{
				BlackPos.insert(std::make_pair(x, y));
			}
			else if (Grid[y][x] == 2)
			{
				WhitePos.insert(std::make_pair(x, y));
			}
		}
	}

	for (auto i : BlackPos)
	{
		//시작점 방문체크를 안해줬는데 문제가 없네..?

		DFS(i, 1);
		if (IsWin[1])
		{
			std::cout << 1 << "\n";
			std::cout << i.second + 1 << " " << i.first + 1;
			break;
		}
	}

	for (auto i : WhitePos)
	{
		//시작점 방문체크를 안해줬는데 문제가 없네..?

		DFS(i, 2);
		if (IsWin[2])
		{
			std::cout << 2 << "\n";
			std::cout << i.second + 1 << " " << i.first + 1;
			break;
		}
	}

	if (IsWin[1] == false && IsWin[2] == false)
	{
		std::cout << 0 << "\n";
	}

	return 0;
}