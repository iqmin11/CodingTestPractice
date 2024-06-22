//���� �ּ� : https://www.acmicpc.net/problem/10597

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <sstream>

std::string NumArr;
int Length;
int LastNum;
std::vector<int> SpaceIndex;

std::string Path;
std::string Buffer;
std::vector<bool> NumCheck;

void BT(int Num, int NumArrIndex)
{
	//0 ~ Length - 1
	if (SpaceIndex.size() == LastNum - 1)
	{
		Path.clear();
		int Index = 0;
		bool Check = true;
		NumCheck = std::vector<bool>(NumCheck.size(), false);

		for (size_t i = 0; i < Length; i++)
		{
			Buffer.push_back(NumArr[i]);

			if (Index >= SpaceIndex.size())
			{
				continue;
			}

			if (SpaceIndex[Index] == i)
			{
				int temp = std::stoi(Buffer);
				Buffer.clear();
				Index++;

				if (temp < 0 || temp > LastNum)
				{
					Check = false;
					return;
				}

				if (NumCheck[temp] == false)
				{
					NumCheck[temp] = true;
				}
				else
				{
					Check = false;
					return;
				}
			}
		}

		if (Check)
		{
			Index = 0;
			for (size_t i = 0; i < Length; i++)
			{
				Path.push_back(NumArr[i]);

				if (Index >= SpaceIndex.size())
				{
					continue;
				}

				if (SpaceIndex[Index] == i)
				{
					Index++;
					Path.push_back(' ');
				}
			}

			std::cout << Path;
			::exit(0);
		}

		return;
	}

	for (int i = Num; i < Length - 1; i++)
	{
		//i = �����̽��ٰ� �� �ε���
		Buffer.push_back(NumArr[NumArrIndex]);
		if (NumArrIndex == i)
		{
			int temp;
			temp = stoi(Buffer);

			if (temp < 0 || temp > LastNum)
			{
				continue;
			}

			if (NumCheck[temp] == false)
			{
				NumCheck[temp] = true;
			}
			else
			{
				continue;
			}
		}
		SpaceIndex.push_back(i);
		BT(i + 1);
		SpaceIndex.pop_back();
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	//���ڿ��� ������ �˸� ���鹮�ڰ� � ���ߵǴ���,
	//1���� ����� ���ڰ� ������ �� �� �ִ�.

	//���̰� 9 ���϶�� ������ ���� == ����, (���������� - 1)���� ������ ����Ѵ�
	//1 2 3 4 5 6 7 8 9

	//���̰� 10 �̻��̶�� 
	//1 2 3 4 5 6 7 8 9 10 11
	// ���� 11 ���������� 10
	// ���� 13 ���������� 11
	// ���� 15 ���������� 12
	// ���̰� (10 + 2a - 1) ������ ���ڴ� (10 + a - 1)
	// Length�� 10 �̻��̸� 
	// Length = Lastnum + a
	// Length = 10 + 2a - 1
	// (Length - 9) / 2 = a
	// LastNum = 10 + a - 1
	// LastNum = Length - ((Length - 9) / 2); ����
	// ������ LastNum - 1�� ����Ѵ�.
	// ������ ��ġ��ų�� �ִ� ���� �� Length - 1 ���� �ִ�.

	std::cin >> NumArr;

	Length = NumArr.size();
	LastNum = -1;
	if (Length <= 9)
	{
		LastNum = Length;
	}
	else
	{
		LastNum = Length - ((Length - 9) / 2);
	}

	//���鹮�ڰ� �� �ε����� BT�� ���մϴ�.
	//���鹮�ڴ� 0 ~ Length - 2 �ε������� (�� Length - 1��) LastNum - 1���� �����մϴ�
	SpaceIndex.reserve(LastNum - 1); //�����̽��� �� �ε����� ����
	NumCheck.resize(LastNum + 1, false);
	
	BT(0);

	return 0;
}