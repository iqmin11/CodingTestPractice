#include <iostream>
#include <vector>
#include <set>

std::vector<std::vector<char>> Grid;
std::vector<std::vector<bool>> IsVisit;
std::vector<std::pair<int, int>> StartPos;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

std::vector<std::pair<int, int>> StackRecord;
std::set<std::set<std::pair<int, int>>> Answer;

bool IsRight()
{
	int CountS = 0;
	int CountY = 0;
	for (const auto& i : StackRecord)
	{
		if (Grid[i.second][i.first] == 'S')
		{
			CountS++;
		}
		else
		{
			CountY++;
		}
	}

	return CountS > CountY;
}

void DFS(int StartX, int StartY)
{
	IsVisit[StartY][StartX] = true;
	StackRecord.push_back(std::make_pair(StartX, StartY));

	if (StackRecord.size() == 7)
	{
		if (IsRight())
		{
			std::set<std::pair<int, int>> temp;
			for (size_t i = 0; i < StackRecord.size(); i++)
			{
				temp.insert(StackRecord[i]);
			}
			Answer.insert(temp);
		}

		IsVisit[StartY][StartX] = false;
		StackRecord.pop_back();
		return;
	}

	for (size_t i = 0; i < 4; i++)
	{
		int CheckX = StartX + dx[i];
		int CheckY = StartY + dy[i];

		if (CheckX < 0 || CheckY < 0 || CheckX >= 5 || CheckY >= 5)
		{
			continue;
		}

		if (IsVisit[CheckY][CheckX])
		{
			continue;
		}

		DFS(CheckX, CheckY);
	}

	IsVisit[StartY][StartX] = false;
	StackRecord.pop_back();
	return;
}

int main()
{
	Grid.resize(5);
	IsVisit.resize(5);
	StartPos.reserve(5 * 5);
	StackRecord.reserve(7);

	for (size_t i = 0; i < 5; i++)
	{
		Grid[i].resize(5);
		IsVisit[i].resize(5, false);
		for (size_t j = 0; j < 5; j++)
		{
			std::cin >> Grid[i][j];
			if (Grid[i][j] == 'S')
			{
				StartPos.push_back(std::make_pair(j,i));
			}
		}
	}

	for (const auto& i : StartPos)
	{
		DFS(i.first, i.second);
	}

	std::cout << Answer.size();

	return 0;
}