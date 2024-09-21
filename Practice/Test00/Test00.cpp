//���� �ּ� : 

#include <iostream>
#include <vector>

int BS_UpperThanValue(const std::vector<int>& FindArr, int UpperValueThan)
{
	int Left = 0;
	int Right = FindArr.size() - 1;

	int Answer = INT32_MAX;

	while (Left <= Right)
	{
		int Mid = (Left + Right) / 2;

		if (FindArr[Mid] == UpperValueThan)
		{
			return FindArr[Mid];
		}
		else if(FindArr[Mid] > UpperValueThan)
		{
			Answer = std::min(FindArr[Mid], Answer);
			Right = Mid - 1;
		}
		else
		{
			Left = Mid + 1;
		}
	}

	return Answer == INT32_MAX ? -1 : Answer;
}

int BS_LowerThanValue(const std::vector<int>& FindArr, int LowerValueThan)
{
	int Left = 0;
	int Right = FindArr.size() - 1;

	int Answer = INT32_MIN;

	while (Left <= Right)
	{
		int Mid = (Left + Right) / 2;

		if (FindArr[Mid] == LowerValueThan)
		{
			return FindArr[Mid];
		}
		else if (FindArr[Mid] > LowerValueThan)
		{
			Right = Mid - 1;
		}
		else
		{
			Answer = std::max(FindArr[Mid], Answer);
			Left = Mid + 1;
		}
	}

	return Answer == INT32_MIN ? -1 : Answer;
}

void Solution(int N, const std::string& M, int Q, const std::vector<std::pair<int, int>> SE)
{
	//1. M�� ������ �迭�� �ϳ� ����� (���߿� ������ ���Ҷ� ����ϸ� �˴ϴ�)
	std::vector<int> PrefixSum;
	PrefixSum.resize(N);

	if (M[0] == '*')
	{
		PrefixSum[0] = 0;
	}
	else
	{
		PrefixSum[0] = M[0] - '0';
	}

	for (int i = 1; i < N; i++)
	{
		int CurAdd = 0;
		if (M[i] != '*')
		{
			CurAdd = M[i] - '0';
		}

		PrefixSum[i] = PrefixSum[i - 1] + CurAdd;
	}

	//2. �ڸ� �������� ���� ���� *�� ���� ū *�� ã�ƾ���. ����Ž���� ���

	std::vector<int> KnotsPos;

	for (int i = 0; i < N; i++)
	{
		if (M[i] == '*')
		{
			KnotsPos.push_back(i);
		}
	}

	for (int i = 0; i < Q; i++)
	{
		int S = SE[i].first;
		int E = SE[i].second;

		int SKnot = BS_UpperThanValue(KnotsPos, S);
		int EKnot = BS_LowerThanValue(KnotsPos, E);

		if (SKnot >= EKnot || SKnot == -1 || EKnot == -1)
		{
			std::cout << 0 << '\n';
			continue;
		}

		std::cout << PrefixSum[EKnot] - PrefixSum[SKnot - 1] << '\n';
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N = 18;
	std::string M = "2113*3*121*212*111";
	int Q = 3;
	std::vector<std::pair<int, int>> SE = { {0,10}, {3,8}, {6, 16} };
	Solution(N, M, Q, SE);

	return 0;
}