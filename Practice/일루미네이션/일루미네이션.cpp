//문제 주소 : https://www.acmicpc.net/problem/5547

#include <iostream>
#include <vector>
#include <queue>

int dx[2][6] = { { -1, 0, -1, 1, -1, 0 } , { 0, 1, -1, 1, 0, 1 } } ;
int dy[] = { -1, -1, 0, 0, 1, 1 };

//1,1 ~ W,H
//0,0 ~ W + 1, H + 1

int W, H;

std::vector<std::vector<bool>> Tile; // true == 건물, false 빈칸
std::vector<std::vector<bool>> IsVisit;

void DebugRender()
{
	std::cout << "////////////////////////////" << std::endl;

	for (size_t y = 0; y <= H + 1; y++)
	{
		if (y % 2 != 0)
		{
			std::cout << " ";
		}

		for (size_t x = 0; x < W + 1; x++)
		{
			std::cout << " " << IsVisit[y][x];
		}
		std::cout << std::endl;
	}

	std::cout << "////////////////////////////" << std::endl;
}

int BFS()
{
	std::queue<std::pair<int, int>> q;
	std::pair<int, int> StartPos = { 0,0 };
	IsVisit[StartPos.second][StartPos.first] = true;
	q.push(StartPos);
	int Answer = 0;

	while (!q.empty())
	{
		std::pair<int, int> CurPos = q.front();
		q.pop();

		for (size_t Dir = 0; Dir < 6; Dir++)
		{
			int CheckX = CurPos.first + dx[CurPos.second % 2][Dir];
			int CheckY = CurPos.second + dy[Dir];

			if (CheckX < 0 || CheckY < 0 || CheckX >= W + 2 || CheckY >= H + 2)
			{
				continue;
			}

			if (IsVisit[CheckY][CheckX])
			{
				continue;
			}

			if (Tile[CheckY][CheckX])
			{
				//건물일때 +1
				Answer++;
				continue;
			}

			q.push(std::make_pair(CheckX, CheckY));
			IsVisit[CheckY][CheckX] = true;
		}

	}

	return Answer;
}


int main()
{
	std::cin >> W >> H;

	Tile.resize(H + 2);
	IsVisit.resize(H + 2);
	for (int y = 0; y <= H + 1; y++)
	{
		Tile[y].resize(W + 2, false);
		IsVisit[y].resize(W + 2, false);
	}

	for (int y = 1; y <= H; y++)
	{
		for (int x = 1; x <= W; x++)
		{
			int temp;
			std::cin >> temp;
			Tile[y][x] = static_cast<bool>(temp);
		}
	}

	std::cout << BFS();

	return 0;

}