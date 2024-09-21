//문제 주소 : https://www.acmicpc.net/problem/16953

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <unordered_map>

int From, To;
std::unordered_map<long long, int> IsVisit;
std::function<long long(long long)> Operation[2];

int BFS()
{
	std::queue<long long> q;
	IsVisit.insert(std::make_pair(From, 1));
	q.push(From);

	while (!q.empty())
	{
		long long CurNode = q.front();
		q.pop();

		for (int i = 0; i < 2; i++)
		{
			long long CheckNode = Operation[i](CurNode);

			if (CheckNode > To)
			{
				continue;
			}

			if (CheckNode == To)
			{
				return IsVisit[CurNode] + 1;
			}

			auto FindIter = IsVisit.find(CheckNode);
			if (FindIter != IsVisit.end())
			{
				continue;
			}

			q.push(CheckNode);
			IsVisit.insert(std::make_pair(CheckNode, IsVisit[CurNode] + 1));
		}
	}

	return -1;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> From >> To;
	Operation[0] = [](long long Value)
		{
			return Value * 2;
		};

	Operation[1] = [](long long Value)
		{
			return Value * 10 + 1;
		};

	std::cout << BFS();

	return 0;
}