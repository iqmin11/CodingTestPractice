//문제 주소 : https://www.acmicpc.net/problem/20040

#include <iostream>
#include <vector>

int N, M;
std::vector<int> Parent;

void Union(int Left, int Right)
{
	if (Left < Right)
	{
		Parent[Right] = Left;
	}
	else
	{
		Parent[Left] = Right;
	}
}

int FindParent(int Value)
{
	if (Parent[Value] == Value)
	{
		return Value;
	}

	Parent[Value] = FindParent(Parent[Value]);
	return Parent[Value];
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;
	Parent.resize(N);
	for (int i = 0; i < N; i++)
	{
		Parent[i] = i;
	}

	for (int i = 0; i < M; i++)
	{
		int FirstNode, SecondNode;

		std::cin >> FirstNode >> SecondNode;

		int FirstParent = FindParent(FirstNode);
		int SecondParent = FindParent(SecondNode);

		if (FirstParent != SecondParent)
		{
			Union(FirstParent, SecondParent);
		}
		else
		{
			std::cout << i + 1;
			return 0;
		}
	}

	std::cout << 0;
	return 0;
}