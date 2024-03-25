//https://www.acmicpc.net/problem/1701

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>

std::vector<std::vector<std::string>> DP;
std::unordered_map<std::string, int> Record; //어떤 부분 문자열이 몇개 있는가

class Comp
{
public : 
	bool operator()(const std::string& Left, const std::string& Right)
	{
		return Left.size() < Right.size();
	}
};

std::vector<std::string> GetPrefix(const std::string& Str)
{
	std::vector<std::string> Prefix;
	Prefix.reserve(Str.size());
	for (size_t i = 0; i < Str.size(); i++)
	{
		std::string Temp = std::string();
		if (i == 0)
		{
			Temp = Str[0];
			Prefix.push_back(Temp);
			continue;
		}

		Temp = Prefix[i - 1] + Str[i];
		Prefix.push_back(Temp);
	}

	return Prefix;
}

std::vector<std::string> GetSuffix(const std::string& Str)
{
	std::vector<std::string> Suffix;
	Suffix.reserve(Str.size());
	for (size_t i = Str.size(); i > 0; i--)
	{
		std::string Temp = std::string();

		for (size_t j = i - 1; j < Str.size(); j++)
		{
			Temp += Str[j];
		}
		Suffix.push_back(Temp);
	}

	return Suffix;
}


std::vector<int> GetPiArr(const std::string& Str)
{
	std::vector<int> PiArr;
	PiArr.resize(Str.size());

	std::vector<std::string> PartialStr = GetPrefix(Str);
	for (size_t i = 0; i < PartialStr.size(); i++)
	{
		std::vector<std::string> Prefix = GetPrefix(PartialStr[i]);
		Prefix.pop_back();
		std::vector<std::string> Suffix = GetSuffix(PartialStr[i]);
		Suffix.pop_back();

		int MaxLenth = 0;

		for (size_t j = 0; j < Prefix.size(); j++)
		{
			if (Prefix[j] == Suffix[j])
			{
				MaxLenth = j + 1;
			}
		}

		PiArr[i] = MaxLenth;
	}

	return PiArr;
}


int KMP(const std::string& Str, const std::string& FindStr)
{
	int Result = 0; 

	size_t n = Str.size();
	size_t m = FindStr.size();
	size_t j = 0;

	std::vector<int> PiArr = GetPiArr(FindStr);
	for (size_t i = 0; i < n; i++)
	{
		while (j > 0 && Str[i] != FindStr[j]) 
		{
			j = PiArr[j - 1];
		}

		if (Str[i] == FindStr[j])
		{
			if (j == m - 1)
			{
				++Result;
				j = PiArr[j]; 
			}
			else
			{
				j++; 
			}
		}
	}

	return Result;
}


int main()
{
	std::string Str; // size == n
	//std::cin >> Str;
	
	Str.resize(5000);
	for (size_t i = 0; i < 5000; i++)
	{
		Str[i] = 'a';
	}

	size_t Lenth = Str.size();
	DP.resize(Lenth);
	for (size_t i = 0; i < DP.size(); i++)
	{
		const size_t size = Lenth - i;
		DP[i].resize(size);
		for (size_t j = 0; j < DP[i].size(); j++)
		{
			DP[i][j].reserve(i + 1);
		}
	}
	
	//DP[1][0] = DP[0][0] + Str[1];
	//DP[1][1] = DP[0][1] + Str[2];
	//DP[1][2] = DP[0][2] + Str[3];
	//
	//DP[2][0] = DP[1][0] + Str[2];
	//DP[2][1] = DP[1][1] + Str[3];
	//
	//DP[3][0] = DP[2][0] + Str[3];

	//DP[a][b] = DP[a-1][b] + Str[a + b]

	for (size_t i = 1; i < Str.size(); i++)
	{
		DP[0][i] = Str[i];
		if (Record.find(DP[0][i]) == Record.end())
		{
			Record.insert(std::make_pair(DP[0][i], KMP(Str, DP[0][i])));
		}
	}

	for (size_t i = 0; i < Str.size() + 1; i++)
	{
		for (size_t j = 0; j < i; j++)
		{
			DP[i - 1][0] += Str[j];
		}

		if (0 < i)
		{
			if (Record.find(DP[i - 1][0]) == Record.end())
			{
				Record.insert(std::make_pair(DP[i - 1][0], KMP(Str, DP[i - 1][0])));
			}
		}
	}

	for (size_t i = 1; i < Str.size(); i++)
	{
		for (size_t j = 1; j < Str.size() - i; j++)
		{
			DP[i][j].resize(DP[i - 1][j].size() + 1);
			DP[i][j] = DP[i - 1][j] + Str[i + j];
			if (Record.find(DP[i][j]) == Record.end())
			{
				Record.insert(std::make_pair(DP[i][j], KMP(Str, DP[i][j])));
			}
		}
	}

	std::priority_queue<std::string, std::vector<std::string>, Comp> pq;
	
	for (auto& i : Record)
	{
		if (i.second >= 2)
		{
			pq.push(i.first);
		}
	}
	
	if (pq.empty())
	{
		std::cout << 0;
	}
	else
	{
		std::cout << pq.top().size();
	}

	return 0;
}