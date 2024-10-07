//문제 주소 : https://www.acmicpc.net/problem/1012

#include <iostream>
#include <vector>
#include <queue>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int T;
	std::cin >> T;

	int dx[] = { 1,0,-1,0 };
	int dy[] = { 0,1,0,-1 };

	while (T-- > 0)
	{
		int X, Y;
		std::cin >> X >> Y;

		int Count;
		std::cin >> Count;

		std::vector<std::vector<bool>> Grid(Y);
		std::vector<std::vector<bool>> IsVisit;

		for (int y = 0; y < Y; y++)
		{
			Grid[y].resize(X, false);
		}

		IsVisit = Grid;

		for (int i = 0; i < Count; i++)
		{
			int CurX, CurY;
			std::cin >> CurX >>  CurY;

			Grid[CurY][CurX] = true;
		}

		int Answer = 0;

		for (int y = 0; y < Y; y++)
		{
			for (int x = 0; x < X; x++)
			{
				if (!Grid[y][x])
				{
					continue;
				}

				if (IsVisit[y][x])
				{
					continue;
				}
				
				//BFS
				std::queue<std::pair<int, int>> q;
				IsVisit[y][x] = true;
				q.push(std::make_pair(x,y));

				while (!q.empty())
				{
					std::pair<int, int> CurPos = q.front();
					q.pop();
					
					for (int i = 0; i < 4; i++)
					{
						int CheckX = CurPos.first + dx[i];
						int CheckY = CurPos.second + dy[i];

						if (CheckX < 0 || CheckY < 0 || CheckX >= X || CheckY >= Y)
						{
							continue;
						}

						if (!Grid[CheckY][CheckX])
						{
							continue;
						}

						if (IsVisit[CheckY][CheckX])
						{
							continue;
						}

						q.push(std::make_pair(CheckX, CheckY));
						IsVisit[CheckY][CheckX] = true;
					}
				}

				Answer++;
			}
		}

		std::cout << Answer << '\n';
	}

	return 0;
}