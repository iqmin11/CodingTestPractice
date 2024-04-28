//문제 주소 : https://www.acmicpc.net/problem/2493

#include <iostream>
#include <stack>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;

	std::cin >> N;

	std::stack<std::pair<int, int>> St; //인덱스, 높이
	St.push(std::make_pair(0, INT32_MAX));

	std::vector<int> Answer;

	for (int i = 1; i <= N; i++)
	{
		int CurHight;
		std::cin >> CurHight;

		while (true)
		{
			int PrevIndex = St.top().first;
			int PrevHight = St.top().second;

			if (PrevHight > CurHight)
			{
				Answer.push_back(PrevIndex);
				St.push(std::make_pair(i, CurHight));
				break;
			}
			else
			{
				St.pop();
			}
		}
	}

	for (size_t i = 0; i < Answer.size(); i++)
	{
		std::cout << Answer[i] << ' ';
	}

	return 0;
}