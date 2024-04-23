//https://www.acmicpc.net/problem/22233

#include <iostream>
#include <unordered_map>
#include <sstream>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::unordered_map<std::string, bool> Keywords;
	int N, M;
	std::cin >> N >> M;

	std::vector<int> Answer;

	for (int i = 0; i < N; i++)
	{
		std::string temp;
		std::cin >> temp;
		Keywords.insert({ temp, true });
	}

	int DeleteCount = 0;

	for (int i = 0; i < M; i++)
	{
		std::string temp;
		std::cin >> temp;
		std::stringstream Buffer(temp);
		while (std::getline(Buffer, temp, ','))
		{
			auto FindIter = Keywords.find(temp);

			if (FindIter != Keywords.end())
			{
				if (FindIter->second == true)
				{
					FindIter->second = false;
					DeleteCount++;
				}
			}
		}
		
		Answer.push_back(Keywords.size() - DeleteCount);
	}

	for (size_t i = 0; i < Answer.size(); i++)
	{
		std::cout << Answer[i] << '\n';
	}
}