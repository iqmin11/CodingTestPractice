//문제 주소 : https://www.acmicpc.net/problem/1339

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cmath>

std::map<char, std::vector<int>> CharInfo; //해당 글자가 해당 자릿수에 몇개 있는가 체크

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		std::string temp;
		std::cin >> temp;

		int DigitIndex = 0;
		for (auto RIter = temp.rbegin(); RIter < temp.rend(); RIter++)
		{
			auto FindIter = CharInfo.find(*RIter);
			if (FindIter == CharInfo.end())
			{
				CharInfo[*RIter].resize(10, 0);
			}
			CharInfo[*RIter][DigitIndex++]++;
		}
	}

	std::priority_queue<int> pq;

	for (auto CalCharInfo : CharInfo)
	{
		int Weight = 0;
		for (int i = 0; i < 10; i++)
		{
			Weight += static_cast<int>(std::pow(10, i)) * CalCharInfo.second[i];
		}
		pq.push(Weight);
	}

	int Answer = 0;
	int Max = 9;
	while (!pq.empty())
	{
		Answer += (Max--) * pq.top();
		pq.pop();
	}

	std::cout << Answer;

	return 0;
}