//문제 주소 : https://www.acmicpc.net/problem/10597

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
		//i = 스페이스바가 들어갈 인덱스
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

	//문자열의 갯수를 알면 공백문자가 몇개 들어가야되는지,
	//1부터 몇까지 숫자가 들어가는지 알 수 있다.

	//길이가 9 이하라면 마지막 숫자 == 길이, (마지막숫자 - 1)개의 공백을 사용한다
	//1 2 3 4 5 6 7 8 9

	//길이가 10 이상이라면 
	//1 2 3 4 5 6 7 8 9 10 11
	// 길이 11 마지막숫자 10
	// 길이 13 마지막숫자 11
	// 길이 15 마지막숫자 12
	// 길이가 (10 + 2a - 1) 마지막 숫자는 (10 + a - 1)
	// Length가 10 이상이면 
	// Length = Lastnum + a
	// Length = 10 + 2a - 1
	// (Length - 9) / 2 = a
	// LastNum = 10 + a - 1
	// LastNum = Length - ((Length - 9) / 2); 성립
	// 공백은 LastNum - 1개 사용한다.
	// 공백을 위치시킬수 있는 곳은 총 Length - 1 곳이 있다.

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

	//공백문자가 들어갈 인덱스를 BT로 정합니다.
	//공백문자는 0 ~ Length - 2 인덱스에서 (총 Length - 1곳) LastNum - 1개를 선택합니다
	SpaceIndex.reserve(LastNum - 1); //스페이스가 들어갈 인덱스를 저장
	NumCheck.resize(LastNum + 1, false);
	
	BT(0);

	return 0;
}