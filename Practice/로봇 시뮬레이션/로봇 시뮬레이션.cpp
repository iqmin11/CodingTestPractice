//���� �ּ� : https://www.acmicpc.net/problem/2174

#include <iostream>
#include <vector>
#include <queue>
#include <string>

//������ �ٺ���
//CurRobot�� ������ �ȹް� ������ ����
//��ɾ� ������ ����� üũ ���ϰ� 1�ڸ� �������� �˰� char�� ����
//�׸��� ����� Ȯ�� ���ϰ� ���� ���� �ٲ�

//Tile, Robot
//Tile�� �κ��� ���� �ִ��� ������, �ִٸ� � �κ��� �ִ����� ��������
//Robot�� Robot�� �κ��� �ε���, ��ġ������ ���� ����.

int X, Y, RobotCount, CmdCount;

struct Tile
{
	int Robot = -1;
};

std::vector<std::vector<Tile>> Grid;
std::queue<std::vector<std::string>> Cmd;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };
// 0 1 2 3 // �� �� �� ��

struct Robot
{
	int Act(char Cmd)
	{
		if (Cmd == 'F')
		{
			int CheckX = Pos.first + dx[Dir];
			int CheckY = Pos.second + dy[Dir];

			if (CheckX < 0 || CheckY < 0 || CheckX >= X || CheckY >= Y)
			{
				//���� �ٱ����� ����
				return -1;
			}

			if (Grid[CheckY][CheckX].Robot != -1)
			{
				//�ٸ� �κ��̶� �浹��
				return Grid[CheckY][CheckX].Robot;
			}

			Grid[Pos.second][Pos.first].Robot = -1;
			Grid[CheckY][CheckX].Robot = 1;

			Pos = std::make_pair(CheckX, CheckY);
		}
		else if (Cmd == 'L')
		{
			Dir = (Dir + 3) % 4;
		}
		else if (Cmd == 'R')
		{
			Dir = (Dir + 1) % 4;
		}

		return 0;
	}

	int RobotID = -1;
	std::pair<int, int> Pos;
	char Dir = -1; // 0 1 2 3 // �� �� �� ��
};

std::vector<Robot> Robots;

void DebugRender()
{
	std::cout << "/////////////////////////////" << std::endl;

	for (size_t y = 0; y < Y; y++)
	{
		for (size_t x = 0; x < X; x++)
		{
			char PrintChar = 'X';

			if (Grid[y][x].Robot != -1)
			{
				PrintChar = Grid[y][x].Robot + '0';
			}

			std::cout << PrintChar << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "/////////////////////////////" << std::endl;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> X >> Y >> RobotCount >> CmdCount;

	Grid.resize(Y);
	for (int y = 0; y < Y; y++)
	{
		Grid[y].resize(X);
	}

	Robots.resize(RobotCount + 1);

	for (int i = 1; i <= RobotCount; i++)
	{
		int tempX, tempY;
		char tempDir;

		std::cin >> tempX >> tempY >> tempDir;

		Robots[i].Pos.first = tempX - 1;
		Robots[i].Pos.second = tempY - 1;

		switch (tempDir)
		{
		case 'E':
			Robots[i].Dir = 0;
			break;
		case 'S':
			Robots[i].Dir = 1;
			break;
		case 'W':
			Robots[i].Dir = 2;
			break;
		case 'N':
			Robots[i].Dir = 3;
			break;
		default:
			break;
		}

		Grid[tempY - 1][tempX - 1].Robot = i;
		Robots[i].RobotID = i;
	}

	for (int i = 0; i < CmdCount; i++)
	{
		std::vector<std::string> tempCmd;
		tempCmd.resize(3);
		std::cin >> tempCmd[0] >> tempCmd[1] >> tempCmd[2];

		Cmd.push(std::move(tempCmd));
	}

	while (!Cmd.empty())
	{
		std::vector<std::string> CurCmd = Cmd.front();
		Cmd.pop();

		int CurRobotIndex = std::stoi(CurCmd[0]);
		Robot& CurRobot = Robots[CurRobotIndex];
		char CurDirCmd = CurCmd[1][0];
		char CurLoopCount = std::stoi(CurCmd[2]);

		for (int i = 0; i < CurLoopCount; i++)
		{
			DebugRender();
			int Result = CurRobot.Act(CurDirCmd);

			if (Result == -1)
			{
				std::cout << "Robot " << CurRobotIndex << " crashes into the wall";
				return 0;
			}
			else if (Result != 0)
			{
				std::cout << "Robot " << CurRobotIndex << " crashes into robot " << Result;
				return 0;
			}
		}
	}

	std::cout << "OK";
	return 0;
}