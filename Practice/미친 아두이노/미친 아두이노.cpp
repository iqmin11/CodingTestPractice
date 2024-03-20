#include <iostream>
#include <vector>
#include <queue>
#include <memory>
#include <list>
#include <map>

std::map<int, std::shared_ptr<struct Robot>> Robots;

struct Robot
{
	static std::list<int> GarbageCollector;

	static void EraseGarbage()
	{
		for (auto CurIter = GarbageCollector.begin(); CurIter != GarbageCollector.end();)
		{
			Robots.erase(*CurIter);
			CurIter = GarbageCollector.erase(CurIter);
		}
	}

	int RobotNum = -1;
	std::pair<int, int> Pos = {-1, -1};
};

std::list<int> Robot::GarbageCollector;

struct Player
{
	std::pair<int, int> Pos = { -1, -1 };
};

struct Tile
{
	void DestroyRobots()
	{
		if (RobotOnTile.size() < 2)
		{
			return;
		}

		for (auto i : RobotOnTile)
		{
			Robot::GarbageCollector.push_back(i->RobotNum);
		}

		RobotOnTile.clear();
	}

	bool IsPlayer = false;
	std::list<std::shared_ptr<Robot>> RobotOnTile;
};

int Y, X;
std::vector<std::vector<Tile>> Grid;
std::string Cmd;
std::shared_ptr<Player> MainPlayer = nullptr;

int dx[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
int dy[] = {1, 1, 1, 0, 0, 0, -1, -1, -1};

void DebugRender()
{
	std::cout << "///////////////////" << std::endl;
	for (size_t y = 0; y < Y; y++)
	{
		for (size_t x = 0; x < X; x++)
		{
			char temp;
			if (Grid[y][x].IsPlayer == true)
			{
				temp = 'I';
			}
			else if (Grid[y][x].RobotOnTile.size() > 0)
			{
				temp = 'R';
			}
			else
			{
				temp = '.';
			}

			std::cout << temp;
		}
		std::cout << std::endl;
	}
	std::cout << "///////////////////" << std::endl;
}

int MoveCount = 0;

void MovePlayer(char Cmd)
{
	size_t CmdIndex = Cmd - '0' - 1;
	if (0 > CmdIndex || CmdIndex > 8)
	{
		std::cout << "OverIndex" << std::endl;
		return;
	}

	std::pair<int, int> PrevPos = MainPlayer->Pos;
	std::pair<int, int> NextPos = std::make_pair(PrevPos.first + dx[CmdIndex], PrevPos.second + dy[CmdIndex]);
	MainPlayer->Pos = NextPos;

	Grid[PrevPos.second][PrevPos.first].IsPlayer = false;
	Grid[NextPos.second][NextPos.first].IsPlayer = true;
	
	++MoveCount;
}

bool IsDefeat = false;

void MoveRobots()
{
	for (auto CurRobot : Robots)
	{
		int CheckMinDistance = INT32_MAX;
		int DirIndex = -1;
		for (size_t k = 0; k < 9; k++)
		{
			int CurCheckX = CurRobot.second->Pos.first + dx[k];
			int CurCheckY = CurRobot.second->Pos.second + dy[k];
			int CurCheckDistance = std::abs(MainPlayer->Pos.first - CurCheckX) + std::abs(MainPlayer->Pos.second - CurCheckY);

			if (CheckMinDistance > CurCheckDistance)
			{
				CheckMinDistance = CurCheckDistance;
				DirIndex = k;
			}
		}

		std::pair<int, int> PrevPos = CurRobot.second->Pos;
		std::pair<int, int> NextPos = std::make_pair(PrevPos.first + dx[DirIndex], PrevPos.second + dy[DirIndex]);
		CurRobot.second->Pos = NextPos;

		if (NextPos == MainPlayer->Pos)
		{
			IsDefeat = true;
			return;
		}
		
		Grid[PrevPos.second][PrevPos.first].RobotOnTile.pop_front();
		Grid[NextPos.second][NextPos.first].RobotOnTile.push_back(CurRobot.second);
	}
}

int main()
{
	std::cin >> Y >> X;
	MainPlayer = std::make_shared<Player>();
	
	Grid.resize(Y);
	int RobotNum = 0;
	for (size_t y = 0; y < Y; y++)
	{
		Grid[y].resize(X);
		std::string temp;
		std::cin >> temp;
		for (size_t x = 0; x < X; x++)
		{
			if (temp[x] == 'I')
			{
				Grid[y][x].IsPlayer = true;
				MainPlayer->Pos = std::make_pair(x, y);
			}
			else if (temp[x] == 'R')
			{
				auto CurIter = (Robots.insert(std::make_pair(RobotNum, std::make_shared<Robot>()))).first;
				CurIter->second->Pos = std::make_pair(x, y);
				CurIter->second->RobotNum = RobotNum++;
				Grid[y][x].RobotOnTile.push_back(CurIter->second);
			}
		}
	}

	std::cin >> Cmd;
	std::queue<char> CmdQ;

	for (size_t i = 0; i < Cmd.size(); i++)
	{
		CmdQ.push(Cmd[i]);
	}

	while (!CmdQ.empty())
	{
		char CurCmd = CmdQ.front();
		CmdQ.pop();

		MovePlayer(CurCmd);
		MoveRobots();

		if (IsDefeat)
		{
			std::cout << "kraj " << MoveCount;
			return 0;
		}

		for (size_t y = 0; y < Y; y++)
		{
			for (size_t x = 0; x < X; x++)
			{
				if (Grid[y][x].RobotOnTile.size() > 1)
				{
					Grid[y][x].DestroyRobots();
				}
			}
		}

		Robot::EraseGarbage();
	}

	for (size_t y = 0; y < Y; y++)
	{
		for (size_t x = 0; x < X; x++)
		{
			char temp;
			if (Grid[y][x].IsPlayer == true)
			{
				temp = 'I';
			}
			else if (Grid[y][x].RobotOnTile.size() > 0)
			{
				temp = 'R';
			}
			else
			{
				temp = '.';
			}
			
			std::cout << temp;
		}
		std::cout << '\n';
	}
}
	