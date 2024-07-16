//문제 주소 : https://www.acmicpc.net/problem/11286

#include <iostream>
#include <queue>

struct Comp
{
	bool operator()(int Left, int Right)
	{
		int LeftABS = std::abs(Left);
		int RightABS = std::abs(Right);

		if (LeftABS == RightABS)
		{
			return Left > Right;
		}

		return LeftABS > RightABS;
	}
};


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;

	std::priority_queue<int, std::vector<int>, Comp> pq;

	for (int i = 0; i < N; i++)
	{
		int Cmd;
		std::cin >> Cmd;

		if (Cmd != 0)
		{
			pq.push(Cmd);
		}
		else
		{
			if (pq.empty())
			{
				std::cout << 0 << '\n';
				continue;
			}

			std::cout << pq.top() << '\n';
			pq.pop();
		}
	}

	return 0;
}