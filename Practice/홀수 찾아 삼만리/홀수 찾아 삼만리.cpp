//문제 주소 : https://www.acmicpc.net/problem/30786

#include <iostream>
#include <vector>
#include <queue>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;
	std::vector<std::queue<int>> Node(2);

	for (int i = 0; i < N; i++)
	{
		int x, y;
		std::cin >> x >> y;
		if ((x + y) % 2 == 0)
		{
			Node[0].push(i);
		}
		else
		{
			Node[1].push(i);
		}
	}

	if (Node[0].empty() || Node[1].empty())
	{
		std::cout << "NO";
		return 0;
	}

	std::cout << "YES\n";
	
	while (!Node[0].empty())
	{
		std::cout << Node[0].front() + 1 << ' ';
		Node[0].pop();
	}

	while (!Node[1].empty())
	{
		std::cout << Node[1].front() + 1 << ' ';
		Node[1].pop();
	}

	return 0;
}