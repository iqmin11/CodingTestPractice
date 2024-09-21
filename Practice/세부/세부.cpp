//문제 주소 : https://www.acmicpc.net/problem/13905

#include <iostream>
#include <vector>
#include <queue>

int VertexCount, EdgeCount;
int Start, End;

std::priority_queue<std::pair<int, std::pair<int, int>>> EdgeInfo;
std::vector<int> Parent;

int FindParent(int Value)
{
	if (Parent[Value] == Value)
	{
		return Value;
	}

	Parent[Value] = FindParent(Parent[Value]);
	return Parent[Value];
}

void Union(int Parent0, int Parent1)
{
	if (Parent0 > Parent1)
	{
		std::swap(Parent0, Parent1);
	}

	Parent[Parent1] = Parent0;
}

int MST()
{
	while (!EdgeInfo.empty())
	{
		int CurCost = EdgeInfo.top().first;
		std::pair<int, int> CurEdge = EdgeInfo.top().second;
		EdgeInfo.pop();

		int FirstParent = FindParent(CurEdge.first);
		int SecondParent = FindParent(CurEdge.second);

		if (FirstParent != SecondParent)
		{
			Union(FirstParent, SecondParent);

			int StartParent = FindParent(Start);
			int EndParent = FindParent(End);
			if (StartParent != EndParent)
			{
				continue;
			}

			return CurCost;
		}
	}

	return 0;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> VertexCount >> EdgeCount;

	std::cin >> Start >> End;
	--Start;
	--End;

	Parent.resize(VertexCount);
	for (int i = 0; i < VertexCount; i++)
	{
		Parent[i] = i;
	}

	for (int i = 0; i < EdgeCount; i++)
	{
		int From, To, Limit;
		std::cin >> From >> To >> Limit;

		EdgeInfo.push(std::make_pair(Limit, std::make_pair(--From, --To)));
	}

	int Answer = MST();

	std::cout << Answer;

	return 0;
}