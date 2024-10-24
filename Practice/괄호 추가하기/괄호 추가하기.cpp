//문제 주소 : https://www.acmicpc.net/problem/16637

#include <iostream>
#include <vector>
#include <string>
#include <set>

std::vector<int> Nums;
std::vector<char> Symbols;
std::set<std::pair<std::vector<int>, std::vector<char>>> IsVisit;

int NumSize, SymbolSize;

int MaxValue = INT32_MIN;

void DFS(const std::vector<int>& CurNums, const std::vector<char>& CurSymbols)
{
	IsVisit.insert(std::make_pair(CurNums, CurSymbols));
	
	if (CurSymbols.empty())
	{
		MaxValue = std::max(CurNums[0], MaxValue);
		return;
	}

	for (int i = 0; i < CurSymbols.size(); i++)
	{
		char CalSymbol = CurSymbols[i];
		int CalNum0 = CurNums[i];
		int CalNum1 = CurNums[i + 1];
		int CheckNum = 0;
		if (CalSymbol == '+')
		{
			CheckNum = CalNum0 + CalNum1;
		}
		else if (CalSymbol == '-')
		{
			CheckNum = CalNum0 - CalNum1;
		}
		else if (CalSymbol == '*')
		{
			CheckNum = CalNum0 * CalNum1;
		}

		//계산한 새 수열
		std::vector<int> CheckNums = CurNums;
		CheckNums.erase(CheckNums.begin() + i);
		auto EraseIter = CheckNums.erase(CheckNums.begin() + i);
		CheckNums.insert(EraseIter, CheckNum);
		std::vector<char> CheckSymbols = CurSymbols;
		CheckSymbols.erase(CheckSymbols.begin() + i);

		if(IsVisit.find(std::make_pair(CheckNums, CheckSymbols)) != IsVisit.end())
		{
			continue;
		}

		DFS(CheckNums, CheckSymbols);
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::string Expression;
	std::cin >> N;
	std::cin >> Expression;

	NumSize = N / 2 + 1;
	SymbolSize = N - NumSize;

	for (int i = 0; i < N; i++)
	{
		if ('0' <= Expression[i] && Expression[i] <= '9')
		{
			Nums.push_back(Expression[i] - '0');
		}
		else
		{
			Symbols.push_back(Expression[i]);
		}
	}

	DFS(Nums, Symbols);

	std::cout << MaxValue;

	return 0;
}