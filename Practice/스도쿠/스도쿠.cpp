//https://www.acmicpc.net/problem/2239

#include <iostream>
#include <vector>

std::string Board;
int Dest = 0;

int dx33[] = { -1, -1, -1, 0, 0, 0, 1, 1, 1 };
int dy33[] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };

bool IsPossible(int CurIndex, char CheckNum)
{
	int CurX = CurIndex % 9;
	int CurY = CurIndex / 9;

	int Center33X = (CurX / 3) * 3 + 1; //33의 중앙점
	int Center33Y = (CurY / 3) * 3 + 1; //33의 중앙점

	for (int i = 0; i < 9; i++)
	{
		if (Board[CurY * 9 + i] == CheckNum) // x체크
		{
			return false;
		}

		if (Board[i * 9 + CurX] == CheckNum) // y체크
		{
			return false;
		}

		int CheckX = Center33X + dx33[i];
		int CheckY = Center33Y + dy33[i];

		if (Board[CheckY * 9 + CheckX] == CheckNum) // 33체크
		{
			return false;
		}
	}

	return true;
}


bool IsFindAnswer = false;
std::string Answer;

void BT(int CurIndex)
{
	if (!Answer.empty())
	{
		return;
	}

	if (CurIndex == Dest + 1)
	{
		Answer = Board;
		return;
	}

	if (Board[CurIndex] != '0') // 0이 아니면 다음 재귀를 돌아야할듯
	{
		BT(CurIndex + 1);
		return;
	}

	for (char i = '1'; i <= '9'; i++) //0이면 1부터 9까지 돌면서
	{
		if (!IsPossible(CurIndex, i)) //현재 인덱스에 i를 넣는게 가능한지 체크
		{
			continue;
		}

		Board[CurIndex] = i;
		BT(CurIndex + 1);
		Board[CurIndex] = '0';
	}
}

int main()
{
	for (int i = 0; i < 9; i++)
	{
		std::string temp;
		std::cin >> temp;
		Board += temp;
	}

	for (int i = 0; i < 81; i++)
	{
		if (Board[i] == '0')
		{
			Dest = std::max(Dest, i);
		}
	}

	BT(0);

	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			std::cout << Answer[y * 9 + x];
		}
		std::cout << '\n';
	}

	return 0;
}