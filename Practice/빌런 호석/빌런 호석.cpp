//���� �ּ� : https://www.acmicpc.net/problem/22251

#include <iostream>
#include <vector>
#include <string>

#define IsOn(BoolArr, N) (BoolArr>> N) & 1

const char LEDNum[10] = { 0b1110111, 0b0010001, 0b0111110, 0b0111011, 0b1011001, 0b1101011, 0b1101111, 0b0110001, 0b1111111, 0b1111011 };

int MaxFloor, DisplayCount, SwitchCount, CurFloor;

std::vector<int> Display;
std::vector<int> ChangeDisplay;
int Answer = -1; // BT�� ���� ��� ����� ���� ���ϸ� �ڱ��ڽ��� ������ ���� ������ �ϳ��� �������. -1�� �ʱ�ȭ

int DisplaytoInt(const std::vector<int>& Display)
{
	std::string Str;
	Str.resize(Display.size());

	for (int i = 0; i < Str.size(); i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (Display[i] == LEDNum[j])
			{
				Str[i] = '0' + j;
				break;
			}
		}
	}

	return std::stoi(Str);
}

void BT(int CurIndex)
{
	if (CurIndex == DisplayCount)
	{
		int ChangeFloor = DisplaytoInt(ChangeDisplay);
		if (ChangeFloor > MaxFloor || ChangeFloor == 0)
		{
			return;
		}

		Answer++;
		return;
	}

	int CurNum = ChangeDisplay[CurIndex];
	for (int i = 0; i < 10; i++)
	{
		int Check = LEDNum[i] ^ ChangeDisplay[CurIndex];
		int DifferCount = 0;

		for (int j = 0; j < 7; j++)
		{
			if (IsOn(Check, j))
			{
				DifferCount++;
			}
		}

		if (DifferCount > SwitchCount)
		{
			continue;
		}

		ChangeDisplay[CurIndex] = LEDNum[i];
		SwitchCount -= DifferCount;

		BT(CurIndex + 1);

		SwitchCount += DifferCount;
		ChangeDisplay[CurIndex] = Display[CurIndex];
	}

}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> MaxFloor >> DisplayCount >> SwitchCount >> CurFloor;

	Display.resize(DisplayCount, 0b0000000);

	std::string CurFloorStr = std::to_string(CurFloor);
	int CurFloorLength = static_cast<int>(CurFloorStr.length());
	int StrIndex = 0;
	for (int i = 0; i < DisplayCount; i++)
	{
		if (DisplayCount - i > CurFloorLength)
		{
			Display[i] = LEDNum[0];
		}
		else
		{
			Display[i] = LEDNum[CurFloorStr[StrIndex++] - '0'];
		}
	}

	ChangeDisplay = Display;

	BT(0);

	std::cout << Answer;

	return 0;
}