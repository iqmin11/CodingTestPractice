//문제 주소 : https://www.acmicpc.net/problem/3190

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

int N;
std::vector<std::vector<bool>> Grid;
std::deque<std::pair<int, int>> Snake;
std::deque<std::pair<int, char>> Cmd;
int CurDir = 0; //동0 남1 서2 북3

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

void DebugRenderer(int Time)
{
	std::vector<std::vector<char>> DebugGrid;
	DebugGrid.resize(N + 1);
	for (int y = 0; y <= N; y++)
	{
		DebugGrid[y].resize(N + 1, 'K');
	}

	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= N; x++)
		{
			if (Grid[y][x] == false)
			{
				DebugGrid[y][x] = 'X';
			}
			else
			{
				DebugGrid[y][x] = 'O';
			}
		}
	}

	for (auto i : Snake)
	{
		DebugGrid[i.second][i.first] = 'S';
	}

	std::cout << "/////////////////////" << std::endl;
	std::cout << Time << std::endl;
	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= N; x++)
		{
			std::cout << DebugGrid[y][x];
		}
		std::cout << std::endl;
	}
	std::cout << "/////////////////////" << std::endl;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	Grid.resize(N + 1);
	for (int y = 0; y <= N; y++)
	{
		Grid[y].resize(N + 1, 0);
	}

	int AppleCount;
	std::cin >> AppleCount;

	for (int i = 0; i < AppleCount; i++)
	{
		int x, y;
		std::cin >> y >> x;

		Grid[y][x] = true;
	}

	int Time = 0;
	Snake.push_back(std::make_pair(1, 1));

	int CmdCount;
	std::cin >> CmdCount;
	for (int i = 0; i < CmdCount; i++)
	{
		int CmdTime;
		char CurCmd;
		std::cin >> CmdTime >> CurCmd;
		Cmd.push_back(std::make_pair(CmdTime, CurCmd));
	}

	while (true)
	{
		if (!Cmd.empty())
		{
			if (Time == Cmd.front().first)
			{
				char CurCmd = Cmd.front().second;
				Cmd.pop_front();

				if (CurCmd == 'D')
				{
					CurDir = (CurDir + 1) % 4;
				}
				else
				{
					CurDir = (CurDir + 3) % 4;
				}
			}
		}

		std::pair<int, int> CurHead = Snake.back();
		int CheckX = CurHead.first + dx[CurDir];
		int CheckY = CurHead.second + dy[CurDir];

		if (CheckX < 1 || CheckY < 1 || CheckX > N || CheckY > N)
		{
			//종료
			std::cout << Time + 1;
			::exit(0);
		}

		std::pair<int, int> CheckHead = std::make_pair(CheckX, CheckY);
		if (std::find(Snake.begin(), Snake.end(), CheckHead) != Snake.end())
		{
			//종료
			std::cout << Time + 1;
			::exit(0);
		}

		Snake.push_back(CheckHead);
		if (Grid[CheckY][CheckX] == false)
		{
			Snake.pop_front();
		}
		else
		{
			Grid[CheckY][CheckX] = false;
		}
		Time++;
	}

	return 0;
}