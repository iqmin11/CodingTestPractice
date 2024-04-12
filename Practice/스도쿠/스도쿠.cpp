//https://www.acmicpc.net/problem/2239

#include <iostream>
#include <map>
#include <stack>

std::map<std::string, bool> IsVisit;
int ZeroCount = 0;
std::string Answer;

bool IsPossible(const std::string& Index, int CurChangePos, char ToNum)
{
	int ChangeX = CurChangePos % 9;
	int ChangeY = CurChangePos / 9;
	int Start33X = (ChangeX / 3) * 3;
	int Start33Y = (ChangeY / 3) * 3;

	for (int i = 0; i < 9; i++)
	{
		if (Index[9 * ChangeY + i] == ToNum)
		{
			return false;
		}

		if (Index[9 * i + ChangeX] == ToNum)
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

bool IsAllZero(const std::string& Index)
{
	for (size_t i = 0; i < Index.size(); i++)
	{
		if (Index[i] == '0')
		{
			return false;
		}
	}

	return true;
}

void DFS(const std::string& CurBoard, int PrevFirstZeroPos)
{
	IsVisit[CurBoard] = true;
	int CurFirstZeroPos = PrevFirstZeroPos;
	while (CurFirstZeroPos < 81)
	{
		if (CurBoard[CurFirstZeroPos] == '0')
		{
			break;
		}
		CurFirstZeroPos++;
	}

	if (CurFirstZeroPos == 81)
	{
		return;
	}
	
	for (size_t i = 1; i <= 9; i++)
	{
		if (!IsPossible(CurBoard, CurFirstZeroPos, '0' + i))
		{
			continue;
		}

		std::string CheckBoard = CurBoard;
		CheckBoard[CurFirstZeroPos] = '0' + i;
		
		if (IsVisit[CheckBoard])
		{
			continue;
		}

		DFS(CheckBoard, CurFirstZeroPos);
	}
}

int main()
{
	std::string Start;
	for (size_t i = 0; i < 9; i++)
	{
		std::string temp;
		std::cin >> temp;
		Start += temp;
	}

	for (size_t i = 0; i < 81; i++)
	{
		if (Start[i] == '0')
		{
			++ZeroCount;
		}
	}

	DFS(Start, 0);

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