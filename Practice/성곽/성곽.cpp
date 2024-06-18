//문제 주소 : https://www.acmicpc.net/problem/2234

#include <iostream>
#include <vector>

int X, Y;
std::vector<std::vector<int>> Grid;
std::vector<std::vector<bool>> IsVisit;
std::vector<std::vector<int>> RoomNumInfo;
std::vector<int> RoomSize;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

int SizeOfRoom = 0;
int MaxSizeOfRoom = INT32_MIN;
int RoomCount = 0;
int CurRoomNum = 0;

void DFS(std::pair<int, int> CurPos)
{
	IsVisit[CurPos.second][CurPos.first] = true;
	int CurWallInfo = Grid[CurPos.second][CurPos.first];
	SizeOfRoom++;
	RoomNumInfo[CurPos.second][CurPos.first] = CurRoomNum;

	for (size_t i = 0; i < 4; i++)
	{
		if ((CurWallInfo >> i) & 1)
		{
			continue;
		}

		int CheckX = CurPos.first + dx[i];
		int CheckY = CurPos.second + dy[i];

		if (CheckX < 0 || CheckY < 0 || CheckX >= X || CheckY >= Y)
		{
			continue;
		}

		if (IsVisit[CheckY][CheckX])
		{
			continue;
		}
		DFS(std::make_pair(CheckX, CheckY));
	}
}

int main()
{
	std::cin >> X >> Y;

	Grid.resize(Y);
	IsVisit.resize(Y);
	RoomNumInfo.resize(Y);

	for (int y = 0; y < Y; y++)
	{
		Grid[y].resize(X);
		IsVisit[y].resize(X, false);
		RoomNumInfo[y].resize(X, -1);
		for (int x = 0; x < X; x++)
		{
			std::cin >> Grid[y][x];
		}
	}

	for (int y = 0; y < Y; y++)
	{
		for (int x = 0; x < X; x++)
		{
			SizeOfRoom = 0;
			if (IsVisit[y][x])
			{
				continue;
			}
			RoomCount++;
			DFS({ x,y });
			RoomSize.push_back(SizeOfRoom);
			MaxSizeOfRoom = std::max(MaxSizeOfRoom, SizeOfRoom);
			CurRoomNum++;
		}
	}

	int MaxSumOfRoomSize = INT32_MIN;

	for (int y = 0; y < Y; y++)
	{
		for (int x = 0; x < X; x++)
		{
			for (int Dir = 2; Dir < 4; Dir++)
			{
				int CheckX = x + dx[Dir];
				int CheckY = y + dy[Dir];

				if (CheckX < 0 || CheckY < 0 || CheckX >= X || CheckY >= Y)
				{
					continue;
				}

				if (RoomNumInfo[y][x] == RoomNumInfo[CheckY][CheckX])
				{
					continue;
				}

				MaxSumOfRoomSize = std::max(RoomSize[RoomNumInfo[y][x]] + RoomSize[RoomNumInfo[CheckY][CheckX]], MaxSumOfRoomSize);
			}
		}
	}


	std::cout << RoomCount << std::endl;
	std::cout << MaxSizeOfRoom << std::endl;
	std::cout << MaxSumOfRoomSize << std::endl;
}