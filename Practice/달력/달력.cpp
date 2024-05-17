//문제 주소 : https://www.acmicpc.net/problem/20207

#include <iostream>
#include <vector>

int N;
int Schedule[366] = {}; //해당 날짜의 스케줄 갯수
std::vector<std::vector<bool>> Grid; //스케줄 그리드화
std::vector<std::vector<bool>> IsVisit; //방문체크

int MinX = INT32_MAX;
int MinY = INT32_MAX;
int MaxX = INT32_MIN;
int MaxY = INT32_MIN;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void DFS(std::pair<int, int> CurPos)
{
	IsVisit[CurPos.first][CurPos.second] = true;

	MinX = std::min(MinX, CurPos.first);
	MinY = std::min(MinY, CurPos.second);

	MaxX = std::max(MaxX, CurPos.first);
	MaxY = std::max(MaxY, CurPos.second);

	for (int Dir = 0; Dir < 4; Dir++)
	{
		int CheckX = CurPos.first + dx[Dir];
		int CheckY = CurPos.second + dy[Dir];

		if (CheckX < 1 || CheckY < 0 || CheckX >= 366 || CheckY >= 1001)
		{
			continue;
		}

		if (!Grid[CheckX][CheckY])
		{
			continue;
		}

		if (IsVisit[CheckX][CheckY])
		{
			continue;
		}

		DFS(std::make_pair(CheckX, CheckY));

	}

}

//달력 스케줄표 그리드를 만들고
//DFS를 돌면서 네방향 가장 끝 좌표를 구하고
//바운딩 랙트를 만들어 넓이 계산

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		int Start, End;
		std::cin >> Start >> End;
		for (int j = Start; j <= End; j++)
		{
			++Schedule[j];
		}
	}

	Grid.resize(366);
	IsVisit.resize(366);
	for (int x = 0; x < 366; x++)
	{
		Grid[x].resize(1000, false);
		IsVisit[x].resize(1000, false);

		int ScheduleCount = Schedule[x];
		for (int y = 0; y < ScheduleCount; y++)
		{
			Grid[x][y] = true;
		}
	}

	int Answer = 0;

	for (int x = 1; x <= 365; x++)
	{
		MinX = INT32_MAX;
		MinY = INT32_MAX;
		MaxX = INT32_MIN;
		MaxY = INT32_MIN;

		if (IsVisit[x][0])
		{
			continue;
		}

		if (!Grid[x][0])
		{
			continue;
		}

		DFS(std::make_pair(x,0));

		Answer += (MaxX - MinX + 1) * (MaxY - MinY + 1);
	}

	std::cout << Answer;

	return 0;
}