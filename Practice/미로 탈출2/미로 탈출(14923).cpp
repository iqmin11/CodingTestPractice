//문제 주소 : https://www.acmicpc.net/problem/14923

#include <iostream>
#include <vector>
#include <queue>

int xMax, yMax;
std::pair<int, int> S, E;

std::vector<std::vector<std::vector<int>>> IsVisit;
std::vector<std::vector<int>> Grid;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

struct Qdata
{
	Qdata(int X, int Y, int IsBrake)
		: xPos(X), yPos(Y), IsBrakeWall(IsBrake)
	{

	}

	int xPos;
	int yPos;
	int IsBrakeWall;
};

int BFS()
{
	std::queue<Qdata> q;
	IsVisit[S.second][S.first][0] = 0;
	q.push(Qdata(S.first, S.second, 0));

	while (!q.empty())
	{
		int CurX = q.front().xPos;
		int CurY = q.front().yPos;
		int IsBrakeWall = q.front().IsBrakeWall;

		q.pop();

		if (E.first == CurX && E.second == CurY)
		{
			return std::min(IsVisit[CurY][CurX][0], IsVisit[CurY][CurX][1]);
		}
		
		for (int i = 0; i < 4; i++)
		{
			int CheckX = CurX + dx[i];
			int CheckY = CurY + dy[i];

			if (CheckX < 0 || CheckY < 0 || CheckX >= xMax || CheckY >= yMax)
			{
				continue;
			}

			//벽이야?
			if (Grid[CheckY][CheckX] == 1)
			{
				//벽을 부신적 있어?
				if (IsBrakeWall == 1)
				{
					continue;
				}

				//이 벽을 부수고 이동한적 있어?
				if (IsVisit[CheckY][CheckX][1] != INT32_MAX)
				{
					continue;
				}

				//벽을 부수고 이동한다
				IsVisit[CheckY][CheckX][1] = IsVisit[CurY][CurX][0] + 1;
				q.push(Qdata(CheckX, CheckY, 1));
				continue;
			}

			if (IsVisit[CheckY][CheckX][IsBrakeWall] != INT32_MAX)
			{
				continue;
			}

			IsVisit[CheckY][CheckX][IsBrakeWall] = IsVisit[CurY][CurX][IsBrakeWall] + 1;
			q.push(Qdata(CheckX, CheckY, IsBrakeWall));
		}
	}
	
	return -1;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> yMax >> xMax;
	std::cin >> S.second >> S.first >> E.second >> E.first;
	--S.first;
	--S.second;
	--E.first;
	--E.second;

	Grid.resize(yMax);
	IsVisit.resize(yMax);
	for (int y = 0; y < yMax; y++)
	{
		Grid[y].resize(xMax);
		IsVisit[y].resize(xMax);
		for (int x = 0; x < xMax; x++)
		{
			std::cin >> Grid[y][x];
			IsVisit[y][x].resize(2, INT32_MAX);
		}
	}

	std::cout << BFS();

	return 0;
}