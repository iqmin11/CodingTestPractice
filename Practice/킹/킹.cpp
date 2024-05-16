//문제 주소 : https://www.acmicpc.net/problem/1063

#include <iostream>
#include <map>
#include <vector>

std::map<std::string, std::pair<int, int>> Move;

void DebugRenderer(const std::pair<int, int>& King, const std::pair<int, int>& Rock)
{
	std::cout << "//////////////////////////////" << std::endl;

	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			if (King == std::make_pair(x, y))
			{
				std::cout << 'K';
			}
			else if (Rock == std::make_pair(x, y))
			{
				std::cout << 'R';
			}
			else
			{
				std::cout << 'X';
			}
		}
		std::cout << std::endl;
	}

	std::cout << "//////////////////////////////" << std::endl;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	//체스판이 왼쪽아래에서 0,0으로 시작한다는 것을 고려하고 방향을 설정해야함
	Move.insert(std::make_pair("R", std::make_pair(1, 0)));
	Move.insert(std::make_pair("L", std::make_pair(-1, 0)));
	Move.insert(std::make_pair("B", std::make_pair(0, -1)));
	Move.insert(std::make_pair("T", std::make_pair(0, 1)));
	Move.insert(std::make_pair("RT", std::make_pair(1, 1)));
	Move.insert(std::make_pair("LT", std::make_pair(-1, 1)));
	Move.insert(std::make_pair("RB", std::make_pair(1, -1)));
	Move.insert(std::make_pair("LB", std::make_pair(-1, -1)));

	std::string KingStartPos, RockStartPos;
	int N;

	std::cin >> KingStartPos >> RockStartPos >> N;

	std::vector<std::string> Cmd;
	Cmd.resize(N);
	for (int i = 0; i < N; i++)
	{
		std::cin >> Cmd[i];
	}

	std::pair<int, int> KingPos;
	KingPos.first = KingStartPos[0] - 'A';
	KingPos.second = KingStartPos[1] - '1';

	std::pair<int, int> RockPos;
	RockPos.first = RockStartPos[0] - 'A';
	RockPos.second = RockStartPos[1] - '1';

	for (int i = 0; i < N; i++)
	{
		std::pair<int, int> Dir = Move[Cmd[i]];
		
		int KingCheckX = KingPos.first + Dir.first;
		int KingCheckY = KingPos.second + Dir.second;

		//왕의 위치가 보드 바깥인지 체크
		if (KingCheckX < 0 || KingCheckY < 0 || KingCheckX >= 8 || KingCheckY >= 8)
		{
			continue;
		}

		//왕의 위치가 돌의 위치와 같은지 체크
		if (std::make_pair(KingCheckX, KingCheckY) == RockPos)
		{
			//돌이 밀리는 위치
			int RockCheckX = RockPos.first + Dir.first;
			int RockCheckY = RockPos.second + Dir.second;

			//돌의 위치가 보드 바깥인지 체크
			if (RockCheckX < 0 || RockCheckY < 0 || RockCheckX >= 8 || RockCheckY >= 8)
			{
				continue;
			}

			RockPos.first = RockCheckX;
			RockPos.second = RockCheckY;
		}

		KingPos.first = KingCheckX;
		KingPos.second = KingCheckY;
	}

	KingStartPos[0] = KingPos.first + 'A';
	KingStartPos[1] = KingPos.second + '1';

	RockStartPos[0] = RockPos.first + 'A';
	RockStartPos[1] = RockPos.second + '1';

	std::cout << KingStartPos << '\n' <<RockStartPos ;

	return 0;
}