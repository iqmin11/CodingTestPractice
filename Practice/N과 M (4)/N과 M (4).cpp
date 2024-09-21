//문제 주소 : https://www.acmicpc.net/problem/15652

#include <iostream>
#include <deque>

int N, L;

std::deque<int> Path;

void BT(int CurStart)
{
	if (static_cast<int>(Path.size()) == L)
	{
		for (auto i : Path)
		{
			std::cout << i << ' ';
		}
		std::cout << '\n';
		return;
	}

	for (int i = CurStart; i <= N; i++)
	{
		Path.push_back(i);
		BT(i);
		Path.pop_back();
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> L;
	BT(1);

	return 0;
}