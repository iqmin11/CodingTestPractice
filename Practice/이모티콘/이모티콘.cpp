//문제 주소 : https://www.acmicpc.net/problem/14226

#include <iostream>
#include <map>
#include <queue>
#include <functional>

int S;
std::map<std::pair<int, int>, bool> IsVisit;
std::vector<std::function<std::pair<int, int>(const std::pair<int, int>&)>> Operation;

std::pair<int, int> Copy(const std::pair<int, int>& Count)
{
	std::pair<int, int> Result(Count);
	Result.second = Result.first;
	return Result;
}

std::pair<int, int> Paste(const std::pair<int, int>& Count)
{
	std::pair<int, int> Result(Count);
	Result.first += Result.second;
	return Result;
}

std::pair<int, int> Delete(const std::pair<int, int>& Count)
{
	std::pair<int, int> Result(Count);
	Result.first--;
	return Result;
}

int BFS()
{
	std::queue<std::pair<int, int>> q; //현재 갯수, 클립보드 카운트

	std::pair<int, int> Start = std::make_pair(1, 0);
	std::map<std::pair<int, int>, int> Depth;
	IsVisit[Start] = true;
	Depth[Start] = 0;
	q.push(Start);

	while (!q.empty())
	{
		std::pair<int, int> CurInfo = q.front();
		q.pop();

		if (CurInfo.first == S)
		{
			return Depth[CurInfo];
		}

		for (int i = 0; i < 3; i++)
		{
			std::pair<int, int> CheckInfo = Operation[i](CurInfo);

			if (CheckInfo.first < 1)
			{
				continue;
			}

			if (IsVisit[CheckInfo])
			{
				continue;
			}

			q.push(CheckInfo);
			IsVisit[CheckInfo] = true;
			Depth[CheckInfo] = Depth[CurInfo] + 1;
		}
	}

	return -1;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> S;
	Operation.push_back(Copy);
	Operation.push_back(Paste);
	Operation.push_back(Delete);

	std::cout << BFS();

	return 0;
}