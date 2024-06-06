//문제 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/70130

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

struct Comp
{
	bool operator()(const std::vector<int>* Left, const std::vector<int>* Right)
	{
		return Left->size() < Right->size();
	}
};

int solution(std::vector<int> a) 
{
	int answer = INT32_MIN;

	//a 안에 있는 원소가 어떤 인덱스에 있는지를 저장하는 자료구조
	std::unordered_map<int, std::vector<int>> ElementsInfo;

	for (int i = 0; i < a.size(); i++)
	{
		ElementsInfo[a[i]].push_back(i);
	}

	//벡터의 사이즈가 크면 우선순위가 높음
	std::priority_queue<std::vector<int>*, std::vector<std::vector<int>*>, Comp> pq;

	for (auto& i : ElementsInfo)
	{
		pq.push(&i.second);
	}

	while (!pq.empty())
	{
		std::vector<int>& CurCheckIndexs = *(pq.top());
		pq.pop();
		int Value = a[CurCheckIndexs[0]];
		int MakePairCount = 0;
		std::pair<int, int> PrevIndex = std::make_pair(-1, -1);

		for (int i = 0; i < CurCheckIndexs.size(); i++)
		{
			int CurIndex = CurCheckIndexs[i];
			bool IsMakePair = false;

			for (int j = -1; j <= 1; j += 2)
			{
				int CheckIndex = CurIndex + j;

				//CheckIndex가 배열을 벗어나면 안됨
				if (CheckIndex < 0 || CheckIndex >= a.size())
				{
					continue;
				}

				//쌍이 같은 Value이면 안됨
				if (a[CheckIndex] == Value)
				{
					continue;
				}

				//이전 정수쌍과 같은 인덱스이면 안됨
				if (PrevIndex.first == CurIndex || PrevIndex.second == CurIndex)
				{
					continue;
				}

				if (PrevIndex.first == CheckIndex || PrevIndex.second == CheckIndex)
				{
					continue;
				}

				//모든걸 만족하면
				MakePairCount++;
				IsMakePair = true;

				int& Small = CurIndex;
				int& Large = CheckIndex;

				if (Small > Large)
				{
					std::swap(Small, Large);
				}

				PrevIndex = std::make_pair(Small, Large);

				break;
			}
		}

		answer = std::max(MakePairCount, answer);
	}

	return answer * 2;
}

int main()
{
	//std::cout << solution({ 0, 1 }) << std::endl;
	//std::cout << "1:" << solution({ 5, 0, 2, 0, 9, 2, 6, 2, 2, 7 }) << std::endl;
	/*std::cout << "1:"<< solution({ 1, 1, 1, 1, 1, 1, 2, 3, 2, 4 }) << std::endl;
	std::cout << "2:"<< solution({5, 2, 3, 3, 5, 3}) << std::endl;
	std::cout << "3:"<< solution({0, 3, 3, 0, 7, 2, 0, 2, 2, 0}) << std::endl;
	std::cout << "4:"<< solution({1, 3, 1, 3, 1, 3, 1, 3}) << std::endl;
	std::cout << "5:"<< solution({1, 5, 4, 4, 1, 3, 1, 3}) << std::endl;
	std::cout << "6:"<< solution({4, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 0, 3}) << std::endl;
	std::cout << "7:"<< solution({0, 0, 0, 2, 3, 4, 3, 5, 3, 1}) << std::endl;*/
	//std::cout << "8:"<< solution({1, 3, 3, 5, 3, 3}) << std::endl;
	/*std::cout << "9:"<< solution({3, 3, 3, 4, 3, 4, 3}) << std::endl;
	std::cout << "10:"<< solution({1, 2, 0}) << std::endl;
	std::cout << "11:"<< solution({1, 2, 1}) << std::endl;
	std::cout << "12:"<< solution({2, 2, 1}) << std::endl;
	std::cout << "13:"<< solution({1, 2, 2}) << std::endl;
	std::cout << "14:"<< solution({2, 2, 2}) << std::endl;
	std::cout << "15:"<< solution({1, 2, 1, 3, 4, 1, 1, 3}) << std::endl;
	std::cout << "16:"<< solution({1, 3, 3, 1, 1, 3, 3, 1}) << std::endl;
	std::cout << "17:"<< solution({1, 3, 3, 1, 3, 3, 1}) << std::endl;
	std::cout << "18:"<< solution({2, 2, 1, 1, 2, 2}) << std::endl;
	std::cout << "19:"<< solution({3, 3, 3, 3, 3, 3, 3}) << std::endl;
	std::cout << "20:"<< solution({4, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 0, 3}) << std::endl;
	std::cout << "21:"<< solution({0}) << std::endl;
	std::cout << "22:"<< solution({1, 1}) << std::endl;
	std::cout << "23:"<< solution({1, 0}) << std::endl;
	std::cout << "24:"<< solution({0, 1, 2, 3, 4, 5}) << std::endl;*/
	return 0;
}