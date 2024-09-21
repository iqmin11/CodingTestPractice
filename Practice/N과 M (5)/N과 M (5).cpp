//문제 주소 : https://www.acmicpc.net/problem/15654

#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

std::deque<int> Path;
int N, M;
std::vector<int> Arr;
std::vector<bool> IsVisit;

void BT()
{
	if (static_cast<int>(Path.size()) == M)
	{
		for (auto i : Path)
		{
			std::cout << i << ' ';
		}
		std::cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (IsVisit[i])
		{
			continue;
		}

		Path.push_back(Arr[i]);
		IsVisit[i] = true;
		BT();
		IsVisit[i] = false;
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
	IsVisit.resize(N, false);
	for (int i = 0; i < N; i++)
	{
		std::cin >> Arr[i];
	}

	std::sort(Arr.begin(), Arr.end());
	BT();

	return 0;
}