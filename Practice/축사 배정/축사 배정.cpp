#include <iostream>
#include <queue>
#include <list>

class Room
{
public:
	int WantedCount = 0;
	bool IsSelected = false;
};

struct CompWantRoom
{
	bool operator()(Room* Left, Room* Right)
	{
		return (*Left).WantedCount > (*Right).WantedCount;
	}
};

class Cow
{
public:
	std::list<Room*> WantRoom;
};

struct CompCow
{
	bool operator()(Cow* Left, Cow* Right)
	{
		return (*Left).WantRoom.size() > (*Right).WantRoom.size();
	}
};

int main()
{
	int N, M;

	std::cin >> N >> M;

	std::vector<Cow> Cows;
	Cows.resize(N);

	std::vector<Room> Rooms;
	Rooms.resize(M);

	std::priority_queue<Cow*, std::vector<Cow*>, CompCow> Cows_Priority;

	for (size_t i = 0; i < N; i++)
	{
		int WantSize;
		std::cin >> WantSize;
		for (size_t j = 0; j < WantSize; j++)
		{
			int WantRoomNum;
			std::cin >> WantRoomNum;
			++Rooms[--WantRoomNum].WantedCount;
			Cows[i].WantRoom.push_back(&Rooms[WantRoomNum]);
		}
		Cows_Priority.push(&Cows[i]);
	}

	int Count = 0;

	while (!Cows_Priority.empty())
	{
		Cow* CurCow = Cows_Priority.top();
		Cows_Priority.pop();

		Room* SelectRoom = nullptr;
		std::priority_queue<Room*, std::vector<Room*>, CompWantRoom> Rooms_Priority;

		for (auto i : CurCow->WantRoom)
		{
			Rooms_Priority.push(i);
		}

		while (!Rooms_Priority.empty())
		{
			SelectRoom = Rooms_Priority.top();
			Rooms_Priority.pop();
			for (auto i : CurCow->WantRoom)
			{
				i->WantedCount -= 1;
			}

			if (SelectRoom->IsSelected == false)
			{
				SelectRoom->IsSelected = true;
				++Count;
				break;
			}
		}
	}

	std::cout << Count << std::endl;
}

