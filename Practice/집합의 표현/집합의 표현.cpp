//문제 주소 : https://www.acmicpc.net/problem/1717

#include <iostream>
#include <vector>

std::vector<int> Parent;

int Find(int Child)
{
	if (Child == Parent[Child])
	{
		return Child;
	}

	Parent[Child] = Find(Parent[Child]);
	return Parent[Child];
}

void Union(int Left, int Right)
{
	int LeftParent = Find(Left);
	int RightParent = Find(Right);

	if (LeftParent < RightParent)
	{
		Parent[RightParent] = LeftParent;
	}
	else if (LeftParent > RightParent)
	{
		Parent[LeftParent] = RightParent;
	}

	return;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, M;
	std::cin >> N >> M;

	Parent.resize(N + 1);
	for (int i = 0; i <= N; i++)
	{
		Parent[i] = i;
	}


	for (int i = 0; i < M; i++)
	{
		int Cmd, Value0, Value1;
		std::cin >> Cmd >> Value0 >> Value1;

		if (Cmd == 0)
		{
			Union(Value0, Value1);
		}
		else if (Cmd == 1)
		{
			int V0Parent = Find(Value0);
			int V1Parent = Find(Value1);

			if (V0Parent == V1Parent)
			{
				std::cout << "YES" << '\n';
			}
			else
			{
				std::cout << "NO" << '\n';
			}
		}
	}

	return 0;
}