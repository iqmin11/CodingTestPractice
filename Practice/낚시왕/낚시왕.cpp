#include <iostream>
#include <vector>
#include <map>
#include <memory>

int dx[] = { 0,0,1,-1 };
int dy[] = { -1,1,0,0 };

int R, C, M;

struct Shark
{
	static std::map<char, std::shared_ptr<Shark>> SharkManager;

	Shark(std::pair<int, int> _Pos, int _Speed, int _Dir, int _Size, char _ID)
		:Pos(_Pos), Speed(_Speed), Dir(_Dir), Size(_Size), ID(_ID)
	{

	}

	void Move()
	{
		int NextPosX = Pos.first;
		int NextPosY = Pos.second;

		NextPosX += dx[Dir] * Speed;
		NextPosY += dy[Dir] * Speed;

		if (NextPosX < 0)
		{  
			NextPosX = abs(NextPosX);
			if (NextPosX >= C)
			{
				NextPosX = (2 * (C - 1)) - NextPosX;
			}
			else
			{
				Dir = 2;
			}
		}

		else if (NextPosY < 0)
		{
			NextPosY = abs(NextPosY);
			if (NextPosY >= R)
			{
				NextPosY = (2 * (R - 1)) - NextPosY;
			}
			else
			{
				Dir = 1;
			}
		}

		else if (NextPosX >= C)
		{
			NextPosX = (2 * (C - 1)) - NextPosX;
			if (NextPosX < 0)
			{
				NextPosX = abs(NextPosX);
			}
			else
			{
				Dir = 3;
			}
		}

		else if (NextPosY >= R)
		{
			NextPosY = (2 * (R - 1)) - NextPosY;
			if (NextPosY < 0)
			{
				NextPosY = abs(NextPosY);
			}
			else
			{
				Dir = 0;
			}
		}

		Pos.first = NextPosX;
		Pos.second = NextPosY;
	}

	std::pair<int, int> Pos;
	int Speed;
	int Dir;
	int Size;
	char ID;
};
std::map<char, std::shared_ptr<Shark>> Shark::SharkManager;

struct Node
{
	std::map<char, std::shared_ptr<Shark>> Sharks;
};

std::vector<std::vector<Node>> Grid;
std::vector<std::vector<Node>> Buffer;

void GridRender()
{
	std::cout << "//////////////////////////////" << std::endl;
	for (size_t y = 0; y < Grid.size(); y++)
	{
		for (size_t x = 0; x < Grid[y].size(); x++)
		{
			if (Grid[y][x].Sharks.empty())
			{
				std::cout << 0;
			}
			else
			{
				std::cout << Grid[y][x].Sharks.begin()->second->ID;
			}
		}
		std::cout << std::endl;
	}

}

int main()
{
	std::cin >> R >> C >> M;

	Grid.resize(R);
	Buffer.resize(R);
	for (size_t y = 0; y < R; y++)
	{
		Grid[y].resize(C);
		Buffer[y].resize(C);
	}

	for (size_t i = 0; i < M; i++)
	{
		std::pair<int, int> Pos;
		int Speed;
		int Dir;
		int Size;

		std::cin >> Pos.second >> Pos.first >> Speed >> Dir >> Size;

		if (Dir == 1 || Dir == 2)
		{
			Speed %= 2 * (R - 1);
		}
		else if (Dir == 3 || Dir == 4)
		{
			Speed %= 2 * (C - 1);
		}

		Pos.first -= 1;
		Pos.second -= 1;
		
		std::shared_ptr<Shark> temp = std::make_shared<Shark>(Pos, Speed, Dir - 1, Size, i + 'A');
		Shark::SharkManager.insert(std::make_pair(i + 'A', temp));

		Grid[Pos.second][Pos.first].Sharks.insert(std::make_pair(i, temp));
	}

	int FishCount = 0;

	//1프레임
	for (size_t Time = 0; Time < C; Time++)
	{
		//GridRender();
		//낚시
		for (size_t y = 0; y < R; y++)
		{
			if (Grid[y][Time].Sharks.empty())
			{
				continue;
			}

			std::shared_ptr<Shark> CatchShark = Grid[y][Time].Sharks.begin()->second;
			char CatchID= CatchShark->ID;
			FishCount += CatchShark->Size;
			Grid[y][Time].Sharks.erase(Grid[y][Time].Sharks.begin());
			std::map<char, std::shared_ptr<Shark>>::iterator EraseIter = Shark::SharkManager.find(CatchID);
			Shark::SharkManager.erase(EraseIter);
			break;
		}
		
		//고기 움직임
		auto CurIter = Shark::SharkManager.begin();
		auto EndIter = Shark::SharkManager.end();
		for (; CurIter != EndIter; )
		{
			std::shared_ptr<Shark> CurShark = CurIter->second;
			CurShark->Move();

			if (!Buffer[CurShark->Pos.second][CurShark->Pos.first].Sharks.empty())
			{
				std::shared_ptr<Shark> CompShark = Buffer[CurShark->Pos.second][CurShark->Pos.first].Sharks.begin()->second;
				if (CurShark->Size > CompShark->Size) //잡아 먹힘
				{
					Buffer[CurShark->Pos.second][CurShark->Pos.first].Sharks.clear();
					Buffer[CurShark->Pos.second][CurShark->Pos.first].Sharks.insert(std::make_pair(CurShark->ID, CurShark));
					
					char EatedID = CompShark->ID;
					std::map<char, std::shared_ptr<Shark>>::iterator EraseIter = Shark::SharkManager.find(EatedID);
					Shark::SharkManager.erase(EraseIter);
					++CurIter;
				}
				else
				{
					char EatedID = CurShark->ID;
					std::map<char, std::shared_ptr<Shark>>::iterator EraseIter = Shark::SharkManager.find(EatedID);
					CurIter = Shark::SharkManager.erase(EraseIter);
				}
			}
			else
			{
				Buffer[CurShark->Pos.second][CurShark->Pos.first].Sharks.insert(std::make_pair(CurShark->ID, CurShark));
				++CurIter;
			}
		}

		//다음 프레임 준비
		Grid = Buffer;

		//버퍼 초기화
		for (size_t y = 0; y < R; y++)
		{
			for (size_t x = 0; x < C; x++)
			{
				Buffer[y][x].Sharks.clear();
			}
		}
	}

	std::cout << FishCount;

	return 0;
}