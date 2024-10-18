//문제 주소 : https://www.acmicpc.net/problem/4195

#include <iostream>
#include <map>
#include <vector>

std::map<std::string, int> Hashing;
std::vector<int> Parent;
std::vector<int> Size;

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

	if (LeftParent != RightParent)
	{
		if (Size[LeftParent] < Size[RightParent])
		{
			std::swap(LeftParent, RightParent);
		}
		Parent[RightParent] = LeftParent;
		Size[LeftParent] += Size[RightParent];
	}
	std::cout << Size[LeftParent] << '\n';
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int T;
	std::cin >> T;
	while (T-- > 0)
	{
		Hashing.clear();
		Parent.clear();
		Size.clear();

		int N;
		std::cin >> N;

		int HashCount = 0;

		for (int i = 0; i < N; i++)
		{
			std::pair<std::string, std::string> Duo;
			std::cin >> Duo.first >> Duo.second;

			auto FirstIter = Hashing.find(Duo.first);
			if (FirstIter == Hashing.end())
			{
				FirstIter = Hashing.insert(std::make_pair(Duo.first, HashCount)).first;
				Parent.push_back(HashCount++);
				Size.push_back(1);
			}

			auto SecondIter = Hashing.find(Duo.second);
			if (SecondIter == Hashing.end())
			{
				SecondIter = Hashing.insert(std::make_pair(Duo.second, HashCount)).first;
				Parent.push_back(HashCount++);
				Size.push_back(1);
			}

			Union(FirstIter->second, SecondIter->second);
		}
	}

	return 0;
}