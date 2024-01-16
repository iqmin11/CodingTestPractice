#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dx[] = {0,1,-1};
int dy[] = {1,0,-1};

std::vector<std::vector<int>> TriArr;
int AllCount = 0;
int Count = 1;

void DebugRender()
{
	for (size_t y = 0; y < TriArr.size(); y++)
	{
		for (size_t x = 0; x < TriArr[y].size(); x++)
		{
			std::cout << TriArr[y][x];
		}
		std::cout << std::endl;
	}
}

vector<int> solution(int n) 
{
	AllCount = (n * (n + 1)) / 2;
	TriArr.resize(n);
	for (size_t i = 0; i < TriArr.size(); i++)
	{
		TriArr[i].resize(i + 1, 0);
	}

	int CurPosX = 0;
	int CurPosY = 0;
	int CurDir = 0;
	TriArr[CurPosY][CurPosX] = Count;

	while (Count++ < AllCount)
	{
		int CheckX = CurPosX + dx[CurDir];
		int CheckY = CurPosY + dy[CurDir];
		if (CheckX < 0 || CheckY < 0 || CheckY >= TriArr.size() || CheckX >= TriArr[CheckY].size() || TriArr[CheckY][CheckX] != 0)
		{
			switch (CurDir)
			{
			case 0:
				CurDir = 1;
				break;
			case 1:
				CurDir = 2;
				break;
			case 2:
				CurDir = 0;
				break;
			default:
				break;
			}
		}
		CheckX = CurPosX + dx[CurDir];
		CheckY = CurPosY + dy[CurDir];
		CurPosX = CheckX;
		CurPosY = CheckY;
		TriArr[CurPosY][CurPosX] = Count;
		DebugRender();
	}

	vector<int> answer;
	answer.resize(AllCount);
	int AnswerCount = 0;
	for (size_t y = 0; y < TriArr.size(); y++)
	{
		for (size_t x = 0; x < TriArr[y].size(); x++)
		{
			answer[AnswerCount++] = TriArr[y][x];
		}
	}
	return answer;
}

int main()
{
	solution(4);

	return 0;
}