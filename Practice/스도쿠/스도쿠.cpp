//https://www.acmicpc.net/problem/2239

#include <iostream>
#include <vector>
#include <map>
#include <stack>

std::string Board;
std::vector<bool> IsVisit;
int ZeroCount = 0;
std::string Answer;
int Start, End;

bool IsPossible(int CurChangePos, char ToNum)
{
	int ChangeX = CurChangePos % 9;
	int ChangeY = CurChangePos / 9;
	int Start33X = (ChangeX / 3) * 3;
	int Start33Y = (ChangeY / 3) * 3;

	for (int i = 0; i < 9; i++)
	{
		if (Board[9 * ChangeY + i] == ToNum)
		{
			return false;
		}

		if (Board[9 * i + ChangeX] == ToNum)
		{
			return false;
		}

		/*int y = i / 9;
		int x = i % 9;

		if (Index[(Start33Y + y) * 9 + (Start33X + x)] == ToNum)
		{
			return false;
		}*/
	}

	return true;
}

void DFS(int CurIndex, char InputNum)
{
	Board[CurIndex] = InputNum;
	IsVisit[CurIndex] = true;

	if (CurIndex == End)
	{
		int a = 0;
	}

	for (int CheckIndex = CurIndex + 1; CheckIndex <= 80; CheckIndex++)
	{
		if (Board[CheckIndex] != '0')
		{
			continue;
		}

		if (IsVisit[CheckIndex])
		{
			continue;
		}

		for (int j = 0; j < 9; j++)
		{
			char Input = '0' + j;
			if (!IsPossible(CheckIndex, Input))
			{
				continue;
			}

			DFS(CheckIndex, Input);
		}

		IsVisit[CurIndex] = false;
		Board[CurIndex] = '0';
		return;
	}
}

int main()
{
	for (size_t i = 0; i < 9; i++)
	{
		std::string temp;
		std::cin >> temp;
		Board += temp;
	}

	IsVisit.resize(81, false);

	for (int i = 0; i < 81; i++)
	{
		if (Board[i] != '0')
		{
			continue;
		}

		Start = std::min(Start, i);
		End = std::max(Start, i);
	}

	DFS(Start, 4);

	for (size_t y = 0; y < 9; y++)
	{
		for (size_t x = 0; x < 9; x++)
		{
			std::cout << Answer[9 * y + x];
		}
		std::cout << '\n';
	}

	int a = 0;
}