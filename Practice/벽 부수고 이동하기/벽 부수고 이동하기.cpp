//문제 주소 : https://www.acmicpc.net/problem/2206

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>

int yMax, xMax;
std::vector<std::string> Grid;
std::vector<std::vector<std::vector<int>>> IsVisit;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int BFS(std::pair<int, int> StartPos)
{
	//x, y, IsUse
	std::queue<std::tuple<int, int, int>> q;
	IsVisit[StartPos.second][StartPos.first][0] = IsVisit[StartPos.second][StartPos.first][0] = 1;
	q.push(std::make_tuple(StartPos.first, StartPos.second, 0));

	while (!q.empty())
	{
		std::tuple<int, int, int>& Front = q.front();
		int CurX = std::get<0>(Front);
		int CurY = std::get<1>(Front);
		int CurIsUse = std::get<2>(Front);

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int CheckX = CurX + dx[i];
			int CheckY = CurY + dy[i];

			if (CheckX < 0 || CheckY < 0 || CheckX >= xMax || CheckY >= yMax)
			{
				continue;
			}

			//벽이야?
			if (Grid[CheckY][CheckX] == '1')
			{
				//응 벽이야

				//벽 부순적 있어?
				if (CurIsUse == 1)
				{
					//응 있어
					continue;
				}

				//아니 없어

				//벽을 부수고 방문 한 적 있어?
				if (IsVisit[CheckY][CheckX][1] != -1)
				{
					//응 있어
					continue;
				}

				//아니 없어

				//벽을 부수고 이동한다
				IsVisit[CheckY][CheckX][1] = IsVisit[CurY][CurX][0] + 1;
				q.push(std::make_tuple( CheckX, CheckY, 1 ));
				continue;
			}

			//아니 벽 아니야

			//방문한 적 있어?
			if(IsVisit[CheckY][CheckX][CurIsUse] != -1)
			{
				//응 있어
				continue;
			}

			//아니 없어
			
			//이동한다
			IsVisit[CheckY][CheckX][CurIsUse] = IsVisit[CurY][CurX][CurIsUse] + 1;
			q.push(std::make_tuple( CheckX, CheckY, CurIsUse ));
		}
	}
	
	int xDestIndex = xMax - 1;
	int yDestIndex = yMax - 1;

	return IsVisit[yDestIndex][xDestIndex][0] == -1 || IsVisit[yDestIndex][xDestIndex][1] == -1 ?
		std::max(IsVisit[yDestIndex][xDestIndex][0], IsVisit[yDestIndex][xDestIndex][1])
		: std::min(IsVisit[yDestIndex][xDestIndex][0], IsVisit[yDestIndex][xDestIndex][1]);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> yMax >> xMax;

	Grid.resize(yMax);
	IsVisit.resize(yMax);
	for (int y = 0; y < yMax; y++)
	{
		std::cin >> Grid[y];
		IsVisit[y].resize(xMax);
		for (int x = 0; x < xMax; x++)
		{
			IsVisit[y][x].resize(2, -1);
		}
	}

	std::cout << BFS(std::make_pair(0, 0));

	return 0;
}