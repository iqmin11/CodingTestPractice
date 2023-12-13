#include <iostream>
#include <set>
#include <vector>
#include <iterator>

std::vector<std::set<int>> LinkNodes;
std::vector<bool> IsVisit;
std::vector<int> PrintStack;

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void DFS(int _Start)
{
	IsVisit[_Start] = true;
	PrintStack.emplace_back(_Start + 1);

	if (IsVisit.size() == PrintStack.size())
	{
		std::copy(PrintStack.begin(), PrintStack.end(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << "\n";

		IsVisit[_Start] = false;
		PrintStack.pop_back();
		return;
	}

	for (auto& LinkNode : LinkNodes[_Start])
	{
		if (!IsVisit[LinkNode])
		{
			DFS(LinkNode);
		}
	}

	IsVisit[_Start] = false;
	PrintStack.pop_back();
}

int main()
{
	Init();

	int N;
	std::cin >> N;
	IsVisit.resize(N, false);
	LinkNodes.resize(N);
	PrintStack.reserve(N);

	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			if (i == j)
			{
				continue;
			}

			LinkNodes[i].insert(j);
		}
	}

	for (size_t i = 0; i < N; i++)
	{
		DFS(i);
	}

	return 0;
}