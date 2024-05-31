//문제 주소 : https://www.acmicpc.net/problem/2665

#include <iostream>
#include <vector>
#include <queue>

//벽을 없애는 방식을 BT로 완전 탐색

int N;
std::vector<std::string> Grid;
std::vector<std::vector<bool>> IsVisit;
std::vector<std::vector<bool>> Init;

int dx[] = { 1, 0 ,-1, 0 };
int dy[] = { 0, 1 ,0, -1 };

bool BFS(std::pair<int, int> StartPos)
{
	std::queue<std::pair<int, int>> q;
	IsVisit[StartPos.second][StartPos.first] = true;
	q.push(StartPos);

	while (!q.empty())
	{
		int CurX = q.front().first;
		int CurY = q.front().first;
		q.pop();

		if (CurX == N - 1 && CurY == N - 1)
		{
			return true;
		}

		for (int Dir = 0; Dir < 4; Dir++)
		{
			int CheckX = CurX + dx[Dir];
			int CheckY = CurY + dy[Dir];

			if (CheckX < 0 || CheckY < 0 || CheckX >= N || CheckY >= N)
			{
				continue;
			}

			if (Grid[CheckY][CheckX] == '0')
			{
				continue;
			}

			if (IsVisit[CheckY][CheckX])
			{
				continue;
			}

			q.push(std::make_pair(CheckX, CheckY));
			IsVisit[CheckY][CheckX] = true;
		}
	}

	return false;
}

std::vector<std::pair<int, int>> Walls;
int WholeWallCount = 0;
std::vector<bool> IsVisit_Wall;

//r개를 선택
int CurDeleteCount = 0;
bool Result = false;
void BT_SelectWall(int CurIndex, int DeleteWallCount)
{
	if (Result)
	{
		return;
	}

	if (CurDeleteCount == DeleteWallCount)
	{
		//BFS를 돌고 결과 보기
		//도착지에 무사히 도착 했다면
		IsVisit = Init;
		Result = BFS(std::make_pair(0,0));
		return;
	}

	for (int i = CurIndex; i < Walls.size(); i++)
	{
		if (IsVisit_Wall[i])
		{
			continue;
		}

		std::pair<int, int> DeleteWallPos = Walls[i];

		IsVisit_Wall[i] = true;
		CurDeleteCount++;
		Grid[DeleteWallPos.second][DeleteWallPos.first] = '1';

		BT_SelectWall(CurIndex + 1, DeleteWallCount);

		Grid[DeleteWallPos.second][DeleteWallPos.first] = '0';
		CurDeleteCount--;
		IsVisit_Wall[i] = false;
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	Grid.resize(N); 
	IsVisit.resize(N);
	for (int y = 0; y < N; y++)
	{
		std::cin >> Grid[y];
		IsVisit[y].resize(N, false);
		for (int x = 0; x < N; x++)
		{
			if (Grid[y][x] == '0')
			{
				Walls.push_back(std::make_pair(x, y));
				IsVisit_Wall.push_back(false);
				WholeWallCount++;
			}
		}
	}
	
	Init = IsVisit;

	int Answer = 0;

	//삭제할 벽의 개수를 하나씩 늘리면서 돌려보기
	for (int i = 0; i < WholeWallCount; i++)
	{
		BT_SelectWall(0, i);
		if (Result)
		{
			Answer = i;
			break;
		}
	}

	std::cout << Answer;

	return 0;
}