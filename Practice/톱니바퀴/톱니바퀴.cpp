//문제 주소 : https://www.acmicpc.net/problem/14891

#include <iostream>
#include <vector>

std::vector<int> Wheel(4, 0);

void RecursivePrev(int RotWheel, int Dir)
{
	int PrevWheel = RotWheel - 1;
	if (PrevWheel >= 0)
	{
		if (((Wheel[RotWheel] >> 1) ^ (Wheel[PrevWheel] >> 5)) & 1)
		{
			//회전 함
			RecursivePrev(PrevWheel, -Dir);
		}
	}

	//11001110 
	if (Dir == 1)
	{
		int Add = 0;
		if (Wheel[RotWheel] & 1)
		{
			Add = 1 << 7;
		}

		//시계방향이면 01100111
		Wheel[RotWheel] >>= 1;
		Wheel[RotWheel] += Add;
	}
	else if (Dir == -1)
	{
		int Add = 0;
		if ((Wheel[RotWheel] >> 7) & 1)
		{
			Add = 1;
			Wheel[RotWheel] -= 1 << 7;
		}

		//반시계면 10011101
		Wheel[RotWheel] <<= 1;
		Wheel[RotWheel] += Add;
	}
}

void RecursiveNext(int RotWheel, int Dir)
{
	int NextWheel = RotWheel + 1;
	if (NextWheel < 4)
	{
		if (((Wheel[RotWheel] >> 5) ^ (Wheel[NextWheel] >> 1)) & 1)
		{
			//회전 함
			RecursiveNext(NextWheel, -Dir);
		}
	}

	//11001110 
	if (Dir == 1)
	{
		int Add = 0;
		if (Wheel[RotWheel] & 1)
		{
			Add = 1 << 7;
		}

		//시계방향이면 01100111
		Wheel[RotWheel] >>= 1;
		Wheel[RotWheel] += Add;
	}
	else if (Dir == -1)
	{
		int Add = 0;
		if ((Wheel[RotWheel] >> 7) & 1)
		{
			Add = 1;
			Wheel[RotWheel] -= 1 << 7;
		}

		//반시계면 10011101
		Wheel[RotWheel] <<= 1;
		Wheel[RotWheel] += Add;
	}
}

void RecursiveStart(int RotWheel, int Dir)
{
	int PrevWheel = RotWheel - 1;
	if (PrevWheel >= 0)
	{
		if (((Wheel[RotWheel] >> 1) ^ (Wheel[PrevWheel] >> 5)) & 1)
		{
			//회전 함
			RecursivePrev(PrevWheel, -Dir);
		}
	}

	int NextWheel = RotWheel + 1;
	if (NextWheel < 4)
	{
		if (((Wheel[RotWheel] >> 5) ^ (Wheel[NextWheel] >> 1)) & 1)
		{
			//회전 함
			RecursiveNext(NextWheel, -Dir);
		}
	}

	//11001110 
	if (Dir == 1)
	{
		int Add = 0;
		if (Wheel[RotWheel] & 1)
		{
			Add = 1 << 7;
		}

		//시계방향이면 01100111
		Wheel[RotWheel] >>= 1;
		Wheel[RotWheel] += Add;
	}
	else if (Dir == -1)
	{
		int Add = 0;
		if ((Wheel[RotWheel] >> 7) & 1)
		{
			Add = 1;
			Wheel[RotWheel] -= 1 << 7;
		}

		//반시계면 10011101
		Wheel[RotWheel] <<= 1;
		Wheel[RotWheel] += Add;
	}
}

int main()
{
	for (int i = 0; i < 4; i++)
	{
		std::string temp;
		std::cin >> temp;
		for (int j = 0; j < 8; j++)
		{
			if (temp[j] == '1')
			{
				Wheel[i] |= 1 << (7 - j);
			}
		}
	}

	int Rot;
	std::cin >> Rot;

	while (Rot-- != 0)
	{
		int RotWheel, Dir;
		std::cin >> RotWheel >> Dir;
		RotWheel -= 1;

		RecursiveStart(RotWheel, Dir);
	}

	int Score = 0;

	for (int i = 0; i < 4; i++)
	{
		if ((Wheel[i] >> 7) & 1)
		{
			Score += 1 << i;
		}
	}

	std::cout << Score;

	return 0;
}