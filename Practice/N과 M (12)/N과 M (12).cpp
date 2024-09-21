//문제 주소 : https://www.acmicpc.net/problem/15666

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <set>

int N, M;

std::vector<int> Arr;
std::deque<int> Path;
std::set<std::deque<int>> Answer;

void BT(int CurNode)
{
	if (static_cast<int>(Path.size()) == M)
	{
		Answer.insert(Path);
		return;
	}

	for (int i = CurNode; i < N; i++)
	{
		Path.push_back(Arr[i]);
		BT(i);
		Path.pop_back();
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;
	Arr.resize(N);
	for (int i = 0; i < N; i++)
	{
		std::cin >> Arr[i];
	}

	std::sort(Arr.begin(), Arr.end());
	
	BT(0);

	for (auto i : Answer)
	{
		for (auto j : i)
		{
			std::cout << j << ' ';
		}
		std::cout << '\n';
	}

	return 0;
}