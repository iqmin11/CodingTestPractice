#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

std::vector<std::string> Grid;
std::vector<std::vector<bool>> IsVisit;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int N = 12;
int M = 6;

std::vector<std::pair<int, int>> RecordStack;

int DFS(std::pair<int, int> _StartPos, char _CheckColor)
{
	IsVisit[_StartPos.second][_StartPos.first] = true;
	int Count = 1;

	for (size_t i = 0; i < 4; i++)
	{
		int CheckX = _StartPos.first + dx[i];
		int CheckY = _StartPos.second + dy[i];

		if (CheckX < 0 || CheckY < 0 || CheckX >= M || CheckY >= N)
		{
			continue;
		}

		if (IsVisit[CheckY][CheckX] == true || Grid[CheckY][CheckX] != _CheckColor)
		{
			continue;
		}

		Count += DFS(std::make_pair(CheckX, CheckY), _CheckColor);
	}

	RecordStack.push_back(_StartPos);
	return Count;
}


int main()
{
	Grid.resize(N);
	IsVisit.resize(N);
	RecordStack.reserve(N*M);
	for (size_t i = 0; i < N; i++)
	{
		std::cin >> Grid[i];
		IsVisit[i].resize(M, false);
	}

	std::map<int, std::set<int>> DestroyBlocks;//x를 key로 y 기록

	while (true) //터지는게 없으면 끝
	{
		//블록을 아래로 내림(하나씩 내리자)
		for (auto CurIter = DestroyBlocks.begin(); CurIter != DestroyBlocks.end(); ++CurIter) // 앞에서부터 돌면 y값이 높은애들부터 체크
		{
			//해당 y값 부터 위로 블록을 돌면서 한칸씩 내림, 끝에는 '.' 추가
			for (auto i : (*CurIter).second)
			{
				for (int j = i; j > 0; --j)
				{
					Grid[j][(*CurIter).first] = Grid[j - 1][(*CurIter).first];
					if (Grid[j - 1][(*CurIter).first] == '.')
					{
						break;
					}
				}
				Grid[0][(*CurIter).first] = '.'; //이런식이 될듯
			}
		}

		DestroyBlocks.clear();

		//모든 좌표를 돌면서 터질 곳 있는 지 체크
		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = 0; j < M; j++)
			{
				std::pair<int, int> StartPos = { j,i };

				if (Grid[i][j] == '.')
				{
					continue;
				}

				int SizeOfSameColor = DFS(StartPos, Grid[i][j]);
				if (SizeOfSameColor >= 4)
				{
					for (auto& DestoryBlock : RecordStack)
					{
						if (DestroyBlocks.find(DestoryBlock.first) != DestroyBlocks.end())
						{
							DestroyBlocks.insert(std::make_pair(DestoryBlock.first, std::set<int>()));
						}
						DestroyBlocks[DestoryBlock.first].insert(DestoryBlock.second);
						//Grid[DestoryBlock.second][DestoryBlock.first] = '.';
					}
				}
				RecordStack.clear();
			}
		}

		if (false) //터질게 없으면
		{
			break;
		}
	}
}