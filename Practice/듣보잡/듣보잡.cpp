//문제 주소 : https://www.acmicpc.net/problem/1764

#include <iostream>
#include <unordered_map>
#include <set>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, M;
	std::cin >> N >> M;
	std::unordered_map<std::string, int> Data;

	std::set<std::string> Answer;
	for (int i = 0; i < N + M; i++)
	{
		std::string temp;
		std::cin >> temp;
		if (++Data[temp] == 2)
		{
			Answer.insert(temp);
		}
	}

	std::cout << Answer.size() << '\n';
	for (auto& i : Answer)
	{
		std::cout << i << '\n';
	}

	return 0;
}