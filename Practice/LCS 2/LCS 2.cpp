//문제 주소 : https://www.acmicpc.net/problem/9252

#include <iostream>
#include <vector>
#include <stack>

int DP[1001][1001];
std::stack<char> Path;

void DFS(std::pair<int, int> CurNode, 
	const std::string& Str0, 
	const std::string& Str1)
{
	if (CurNode.first == 0 || CurNode.second == 0)
	{
		return;
	}

	char CheckChar0 = Str0[CurNode.first - 1];
	char CheckChar1 = Str1[CurNode.second - 1];
	
	if (CheckChar0 == CheckChar1)
	{
		Path.push(CheckChar0);
		DFS(std::make_pair(CurNode.first - 1, CurNode.second - 1), Str0, Str1);
	}
	else
	{
		std::pair<int, int> NextNode;
		if (DP[CurNode.second][CurNode.first - 1] > DP[CurNode.second - 1][CurNode.first])
		{
			NextNode = std::make_pair(CurNode.first - 1, CurNode.second);
		}
		else
		{
			NextNode = std::make_pair(CurNode.first, CurNode.second - 1);
		}
		DFS(NextNode, Str0, Str1);
	}
}


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::string Str0, Str1;
	std::cin >> Str0 >> Str1;

	for (size_t i = 1; i <= Str1.size(); i++)
	{
		for (size_t j = 1; j <= Str0.size(); j++)
		{
			if (Str0[j - 1] == Str1[i - 1])
			{
				DP[i][j] = DP[i - 1][j - 1] + 1;
			}
			else
			{
				DP[i][j] = std::max(DP[i - 1][j], DP[i][j - 1]);
			}
		}
	}

	std::cout << DP[Str1.size()][Str0.size()] << '\n';

	DFS(std::make_pair(Str0.size(), Str1.size()), Str0, Str1);

	while (!Path.empty())
	{
		std::cout << Path.top();
		Path.pop();
	}
	
	return 0;
}