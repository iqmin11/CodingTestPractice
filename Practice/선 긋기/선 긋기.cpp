//https://www.acmicpc.net/problem/2170

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;

	std::vector<std::pair<int, bool>> Lines; //위치, 시작점? 끝점?
	Lines.resize(N * 2);

	for (int i = 0; i < N * 2; i++)
	{
		std::cin >> Lines[i].first;

		if (i % 2 == 0)
		{
			Lines[i].second = false; //시작점은 false
		}
		else
		{
			Lines[i].second = true; //끝점은 true
		}
	}

	std::sort(Lines.begin(), Lines.end()); //이러면 정렬을해도
	//시작점과 끝점이 만나는 지점을 그냥 하나의 선분으로 처리할 수 있다
	//만약 그 둘을 이어지지않은 다른 선분으로 처리를 하려고 한다면, 시작점을 true 끝점을 false로 하면 된다

	int CurLineCount = 0;
	int CurLineStart = INT32_MAX;
	int CurLineEnd = INT32_MIN;
	int LineLength = 0;

	for (int i = 0; i < N*2; i++)
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
			//길이 재는것 시작
			CurLineStart = Lines[i].first;
		}
		else if (CurLineCount == 0 && PrevLineCount == 1)
		{
			//길이 재는것 종료
			CurLineEnd = Lines[i].first;
			LineLength += CurLineEnd - CurLineStart;
		}
	}

	std::cout << LineLength;

	return 0;
}