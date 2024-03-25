// https://www.acmicpc.net/problem/16472

#include <iostream>
#include <unordered_map>

void Init()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
}

int main()
{
	Init();

	int n;
	std::string Data;

	std::cin >> n;
	std::cin >> Data;

	int Size = Data.size();

	int right = 0;
	std::unordered_map<char, int> CaseCheck; //어떤 글자가 몇개
	int MaxCount = INT32_MIN;

	for (int left = 0; left < Data.size(); left++)
	{
		while (CaseCheck.size() <= n && right < Data.size())
		{
			CaseCheck[Data[right]] += 1;
			right++;
		}

		if (CaseCheck.size() > n)
		{
			MaxCount = std::max(MaxCount, right - left - 1);
		}
		else
		{
			MaxCount = std::max(MaxCount, right - left);
		}

		auto FindIter = CaseCheck.find(Data[left]);
		FindIter->second -= 1;
		if (FindIter->second == 0)
		{
			CaseCheck.erase(FindIter);
		}
	}

	std::cout << MaxCount;

	return 0;
}