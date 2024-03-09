//https://www.acmicpc.net/problem/3109

#include <iostream>
#include <queue>
#include <vector>
#include <list>

int R, C;
int dx[] = { 1,1,1 };
int dy[] = { -1,0,1 };
int Count = 0;

std::vector<std::string> Grid;
std::vector<std::vector<bool>> IsVisit;

void DebugRender()
{
	std::cout << "//////////////////////" << '\n';
	for (size_t i = 0; i < Grid.size(); i++)
	{
		for (size_t j = 0; j < Grid[i].size(); j++)
		{
			std::cout << Grid[i][j];
		}
		std::cout << '\n';
	}

	std::cout << "//////////////////////" << '\n';
}

std::list<std::pair<int, int>> StackRecord;
bool DFS(std::pair<int, int> _CurPos, int _DestC)
{
	IsVisit[_CurPos.second][_CurPos.first] = -1;
	Grid[_CurPos.second][_CurPos.first] = Count + '0';
	StackRecord.push_back(_CurPos);
	DebugRender();
	bool result = false;

	if (_CurPos.first == _DestC || result == true)
	{
		return true;
	}

	for (size_t i = 0; i < 3; i++)
	{
		int CheckX = _CurPos.first + dx[i];
		int CheckY = _CurPos.second + dy[i];
		if (CheckX < 0 || CheckY < 0 || CheckX >= C || CheckY >= R)
		{
			continue;
		}

		if (IsVisit[CheckY][CheckX])
		{
			continue;
		}

		if (Grid[CheckY][CheckX] == 'x')
		{
			continue;
		}
		
		result = DFS({ CheckX , CheckY }, _DestC);
	}
	
	StackRecord.pop_back();
	IsVisit[_CurPos.second][_CurPos.first] = false;
	Grid[_CurPos.second][_CurPos.first] = '.';
	return result;
}

int main()
{
	std::cin >> R >> C;
	Grid.resize(R);
	IsVisit.resize(R);
	for (size_t i = 0; i < R; i++)
	{
		std::cin >> Grid[i];
		IsVisit[i].resize(C,false);
	}

	for (size_t i = 0; i < R; i++)
	{
		std::pair<int, int> StartPos = { 0,i };
		if (IsVisit[StartPos.second][StartPos.first])
		{
			continue;
		}

		if (DFS(StartPos, C - 1))
		{
			Count++;
		}

		StackRecord.clear();
	}

	std::cout << Count;
}