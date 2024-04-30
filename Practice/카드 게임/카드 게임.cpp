//巩力 林家 : https://www.acmicpc.net/problem/11062

#include <iostream>
#include <vector>

int DP[1001][1001];
bool MyTurn = false;

int MiniMaxTree(int CurLeft, int CurRight, const std::vector<int>& Board)
{
	MyTurn = !MyTurn;

	if (CurLeft > CurRight)
	{
		return 0;
	}

	if (DP[CurLeft][CurRight] != 0)
	{
		return DP[CurLeft][CurRight];
	}

	if (MyTurn) //辟快
	{
		int LeftPick = Board[CurLeft] + MiniMaxTree(CurLeft + 1, CurRight, Board);
		int RightPick = Board[CurRight] + MiniMaxTree(CurLeft, CurRight - 1, Board);

		DP[CurLeft][CurRight] = std::max(LeftPick, RightPick);
	}
	else
	{
		int LeftPick = MiniMaxTree(CurLeft + 1, CurRight, Board);
		int RightPick = MiniMaxTree(CurLeft, CurRight - 1, Board);

		DP[CurLeft][CurRight] = std::min(LeftPick, RightPick);
	}

	return DP[CurLeft][CurRight];
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int TestCase;
	std::cin >> TestCase;

	for (int T = 0; T < TestCase; T++)
	{
		int CardSize;
		std::cin >> CardSize;
		std::vector<int> Board;
		Board.resize(CardSize);

		for (int i = 0; i < CardSize; i++)
		{
			std::cin >> Board[i];
		}

		MiniMaxTree(0, CardSize - 1, Board);
		int Answer = DP[0][CardSize - 1];
		int a = 0;
	}

	return 0;
}