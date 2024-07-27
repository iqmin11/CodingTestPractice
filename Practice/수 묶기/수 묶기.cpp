#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	//남은 작은 음수는 1개 아니면 0개
	//1개가 남았다면, 0이 있다면... 0이랑 묶고
	//0이 없으면 놔둬
	//1은 곱했을때 자기 자신이 나오기 때문에 그냥 놔두는게 더 큰 숫자임.

	int N;
	std::cin >> N;

	//(음수)와 (0), (양수)로 나눠서...
	std::priority_queue<int> Plus;
	std::priority_queue<int, std::vector<int>, std::greater<int>> Minus;
	std::priority_queue<int> Zero;
	std::priority_queue<int> One;

	for (int i = 0; i < N; i++)
	{
		int temp;
		std::cin >> temp;
		if (temp < 0)
		{
			Minus.push(temp);
		}
		else if (temp > 1)
		{
			Plus.push(temp);
		}
		else if (temp == 1)
		{
			One.push(temp);
		}
		else
		{
			Zero.push(temp);
		}
	}

	//정렬하고, 절대값이 큰놈끼리 먼저 곱하고..
	int Answer = 0;
	std::vector<int> temp(2);

	while (Minus.size() >= 2)
	{
		int Loop = 2;
		while (Loop-- > 0)
		{
			temp[Loop] = Minus.top();
			Minus.pop();
		}

		Answer += temp[0] * temp[1];
	}

	if (!Minus.empty() && !Zero.empty())
	{
		Minus.pop();
		Zero.pop();
	}

	while (Plus.size() >= 2)
	{
		int Loop = 2;
		while (Loop-- > 0)
		{
			temp[Loop] = Plus.top();
			Plus.pop();
		}

		Answer += temp[0] * temp[1];
	}

	while (!Minus.empty())
	{
		Answer += Minus.top();
		Minus.pop();
	}

	while (!Plus.empty())
	{
		Answer += Plus.top();
		Plus.pop();
	}

	while (!One.empty())
	{
		Answer += One.top();
		One.pop();
	}

	std::cout << Answer;

	return 0;
}