//문제 주소 : https://www.acmicpc.net/problem/15650

#include <iostream>
#include <deque>

int N, M;
std::deque<int> Path;

void BT(int CurIndex)
{
	if (Path.size() == M)
	{
		for (int i = 0; i < M; i++)
		{
			std::cout << Path[i] << ' ';
		}
		std::cout << '\n';
		return;
	}

	for (int i = CurIndex; i <= N; i++)
	{
		Path.push_back(i);
		BT(i + 1);
		Path.pop_back();
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;
	BT(1);

	return 0;
}