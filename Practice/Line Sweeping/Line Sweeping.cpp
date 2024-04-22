#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::pair<int, bool>> Lines; //점의 위치, 시작점? 끝점?
//시작점은 false, 끝점은 true
//시작점과 끝점이 만나는 지점을 그냥 하나의 선분으로 처리할 수 있다
//만약 그 둘을 이어지지않은 다른 선분으로 처리를 하려고 한다면, 시작점을 true 끝점을 false로 하면 된다

//반드시 Lines는 정렬되어있어야한다!!!!!!!!!!!!!!!!!!!!!!!!!

void LineSweeping()
{
	std::sort(Lines.begin(), Lines.end());

	int CurLineCount = 0;
	int CurLineStart = INT32_MAX;
	int CurLineEnd = INT32_MIN;
	int Answer = 0;

	for (int i = 0; i < Lines.size(); i++)
	{
		int PrevLineCount = CurLineCount;

		if (Lines[i].second == false)
		{
			CurLineCount++;
		}
		else
		{
			CurLineCount--;
		}

		if (CurLineCount == 1 && PrevLineCount == 0)
		{
			//Line의 시작
			CurLineStart = Lines[i].first;
		}
		else if (CurLineCount == 0 && PrevLineCount == 1)
		{
			//Line의 끝
			CurLineEnd = Lines[i].first;
			
			//여기서 하고자 하는 것을 할 것
			//선의 갯수를 센다던지
			//선의 길이를 합한다던지 등...
		}
	}
}

int main()
{

}