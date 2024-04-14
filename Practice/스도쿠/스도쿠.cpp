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

	int Center33X = (CurX / 3) * 3 + 1; //33�� �߾���
	int Center33Y = (CurY / 3) * 3 + 1; //33�� �߾���

	for (int i = 0; i < 9; i++)
	{
		if (Board[CurY * 9 + i] == CheckNum) // xüũ
		{
			return false;
		}

		if (Board[i * 9 + CurX] == CheckNum) // yüũ
		{
			return false;
		}

		int CheckX = Center33X + dx33[i];
		int CheckY = Center33Y + dy33[i];

		if (Board[CheckY * 9 + CheckX] == CheckNum) // 33üũ
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

	if (Board[CurIndex] != '0') // 0�� �ƴϸ� ���� ��͸� ���ƾ��ҵ�
	{
		BT(CurIndex + 1);
		return;
	}

	for (char i = '1'; i <= '9'; i++) //0�̸� 1���� 9���� ���鼭
	{
		if (!IsPossible(CurIndex, i)) //���� �ε����� i�� �ִ°� �������� üũ
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