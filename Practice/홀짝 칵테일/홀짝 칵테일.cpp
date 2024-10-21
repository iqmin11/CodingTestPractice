//문제 주소 : https://www.acmicpc.net/problem/21312

#include <iostream>
#include <queue>
#include <stack>

struct Cmp
{
	bool operator()(int Left, int Right)
	{
		int LeftMod = Left % 2;
		int RightMod = Right % 2;
		return LeftMod == RightMod ? Left < Right : LeftMod < RightMod;
	}
};

std::stack<int> Path;
std::priority_queue<int, std::vector<int>, Cmp> pq;
int Liquid[3];

void BT(int Length, int CurIndex)
{
	if (Length == Path.size())
	{
		std::stack<int> MulElements = Path;
		int Result = 1;
		while (!MulElements.empty())
		{
			Result *= Liquid[MulElements.top()];
			MulElements.pop();
		}
		pq.push(Result);
		return;
	}

	for (int i = CurIndex; i < 3; i++)
	{
		Path.push(i);
		BT(Length, i + 1);
		Path.pop();
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	for (int i = 0; i < 3; i++)
	{
		std::cin >> Liquid[i];
	}

	for (int i = 1; i <= 3; i++)
	{
		BT(i, 0);
	}

	std::cout << pq.top();

	return 0;
}