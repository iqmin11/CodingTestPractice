//https://www.acmicpc.net/problem/18188
#include <iostream>
#include <vector>
#include <list>

enum class Dir : char
{
	Non = -1,
	D,
	S,
	A,
	W
};

int Y, X;
std::vector<std::string> Grid;
int N;
std::vector<std::vector<Dir>> MaridCmd;
std::pair<int, int> StartPos;
std::pair<int, int> DestPos;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

void DebugRender()
{
	std::cout << "////////////////////" << std::endl;

	for (size_t y = 0; y < Y; y++)
	{
		for (size_t x = 0; x < X; x++)
		{
			std::cout << Grid[y][x];
		}
		std::cout << std::endl;
	}

	std::cout << "////////////////////" << std::endl;
}

std::list<Dir> RecordStack;
bool IsGoal = false;

void DFS(std::pair<int, int> CurPos, Dir CurDir = Dir::Non)
{
	Grid[CurPos.second][CurPos.first] = 'D';
	int CurMoveCount = RecordStack.size();
	RecordStack.push_back(CurDir);
	DebugRender();

	if (CurPos == DestPos)
	{
		IsGoal = true;
		return;
	}

	if (CurMoveCount == N)
	{
		RecordStack.pop_back();
		Grid[CurPos.second][CurPos.first] = '.';
		return;
	}

	for (size_t i = 0; i < 4; i++)
	{
		const std::vector<Dir>& PossibleDir = MaridCmd[CurMoveCount];

		if (PossibleDir[0] != static_cast<Dir>(i) && PossibleDir[1] != static_cast<Dir>(i))
		{
			continue;
		}

		int CheckX = CurPos.first + dx[i];
		int CheckY = CurPos.second + dy[i];

		if (CheckX < 0 || CheckY < 0 || CheckX >= X || CheckY >= Y)
		{
			continue;
		}

		if (Grid[CheckY][CheckX] == '@')
		{
			continue;
		}

		if (Grid[CheckY][CheckX] == 'D')
		{
			continue;
		}

		DFS(std::make_pair(CheckX, CheckY), static_cast<Dir>(i));
		if (IsGoal)
		{
			return;
		}
	}

	RecordStack.pop_back();
	Grid[CurPos.second][CurPos.first] = '.';
}

int main()
{
	std::cin >> Y >> X;

	Grid.resize(Y);
	
	for (size_t y = 0; y < Y; y++)
	{
		Grid[y].resize(X);
		std::string temp;
		std::cin >> temp;
		for (size_t x = 0; x < X; x++)
		{
			if (temp[x] == 'D')
			{
				StartPos = { x,y };
				Grid[y][x] = '.';
			}
			else if(temp[x] == 'Z')
			{
				DestPos = { x,y };
				Grid[y][x] = '.';
			}
			else if(temp[x] == '@')
			{
				Grid[y][x] = '@';
			}
			else
			{
				Grid[y][x] = '.';
			}
		}
	}

	std::cin >> N;
	MaridCmd.resize(N);
	for (size_t i = 0; i < N; i++)
	{
		MaridCmd[i].resize(2);
		for (size_t j = 0; j < 2; j++)
		{
			char temp;
			std::cin >> temp;
			if (temp == 'D')
			{
				MaridCmd[i][j] = Dir::D;
			}
			else if(temp == 'S')
			{
				MaridCmd[i][j] = Dir::S;
			}
			else if (temp == 'A')
			{
				MaridCmd[i][j] = Dir::A;
			}
			else if (temp == 'W')
			{
				MaridCmd[i][j] = Dir::W;
			}
		}
	}

	DFS(StartPos);
	
	if (RecordStack.empty())
	{
		std::cout << "NO";
	}
	else
	{
		std::cout << "YES" << std::endl;
		while (!RecordStack.empty())
		{
			switch (RecordStack.front())
			{
			case Dir::W :
				std::cout << "W";
				break;
			case Dir::A :
				std::cout << "A";
				break;
			case Dir::S :
				std::cout << "S";
				break;
			case Dir::D :
				std::cout << "D";
				break;
			default:
				break;
			}

			RecordStack.pop_front();
		}
	}
}