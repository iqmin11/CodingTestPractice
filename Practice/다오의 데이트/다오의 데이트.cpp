//문제 주소 : https://www.acmicpc.net/problem/18188

#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <map>
#include <queue>

int xMax, yMax;
std::vector<std::string> Grid;
std::vector<std::vector<std::pair<int, char>>> IsVisit; //Depth, InDepthCmd
std::pair<int, int> S, E;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
std::map<char, int> Hashing;

int MoveCount;
std::vector<std::string> Cmds;

bool BFS()
{
	std::queue<std::pair<int, int>> q;
	IsVisit[S.second][S.first].first = 0;
	q.push(S);

	while (!q.empty())
	{
		std::pair<int, int> CurPos = std::move(q.front());
		q.pop();

		if (E == CurPos)
		{
			return true;
		}

		int CurX = CurPos.first;
		int CurY = CurPos.second;
		int CurDepth = IsVisit[CurY][CurX].first;

		if (CurDepth >= MoveCount)
		{
			continue;
		}

		std::string& CurCmd = Cmds[CurDepth];


		for (int i = 0; i < 2; i++)
		{
			
			int CheckX = CurX + dx[Hashing[CurCmd[i]]];
			int CheckY = CurY + dy[Hashing[CurCmd[i]]];

			if (CheckX < 0 || CheckY < 0 || CheckX >= xMax || CheckY >= yMax)
			{
				continue;
			}

			if (IsVisit[CheckY][CheckX].first != -1)
			{
				continue;
			}

			if (Grid[CheckY][CheckX] == '@')
			{
				continue;
			}

			IsVisit[CheckY][CheckX].first = IsVisit[CurY][CurX].first + 1;
			IsVisit[CheckY][CheckX].second = CurCmd[i];
			q.push(std::make_pair(CheckX, CheckY));
		}
	}

	return false;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	Hashing.insert(std::make_pair('D', 0));
	Hashing.insert(std::make_pair('S', 1));
	Hashing.insert(std::make_pair('A', 2));
	Hashing.insert(std::make_pair('W', 3));

	std::cin >> yMax >> xMax;

	Grid.resize(yMax);
	IsVisit.resize(yMax);
	for (int y = 0; y < yMax; y++)
	{
		std::cin >> Grid[y];
		IsVisit[y].resize(xMax, std::make_pair(-1, '\0'));
		for (int x = 0; x < xMax; x++)
		{
			if (Grid[y][x] == 'D')
			{
				S = std::make_pair(x, y);
			}
			else if (Grid[y][x] == 'Z')
			{
				E = std::make_pair(x, y);
			}
		}
	}

	std::cin >> MoveCount;
	Cmds.resize(MoveCount);

	for (int i = 0; i < MoveCount; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			char tempChar;
			std::cin >> tempChar;
			Cmds[i].push_back(tempChar);
		}
	}

	bool IsSuccess = BFS();

	std::cout << (IsSuccess ? "YES" : "NO") << '\n';
	std::vector<char> Answer;
	std::pair<int, int> CurCheckPos = E;

	if (IsSuccess)
	{
		while (IsVisit[CurCheckPos.second][CurCheckPos.first].second != '\0')
		{
			Answer.push_back(IsVisit[CurCheckPos.second][CurCheckPos.first].second);
			switch (Answer.back())
			{
			case 'W':
				CurCheckPos.second += 1;
				break;
			case 'A':
				CurCheckPos.first += 1;
				break;
			case 'S':
				CurCheckPos.second -= 1;
				break;
			case 'D':
				CurCheckPos.first -= 1;
				break;
			default:
				break;
			}
		}

		for (auto CurRIter = Answer.rbegin(); CurRIter != Answer.rend(); ++CurRIter)
		{
			std::cout << *CurRIter;
		}
	}

	return 0;
}