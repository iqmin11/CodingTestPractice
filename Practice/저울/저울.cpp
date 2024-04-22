//https://www.acmicpc.net/problem/2437

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int N;
std::vector<int> IsVisit;
std::vector<int> Nums;

std::set<int> SumResult;

int Answer = -1;


void BT(int CurSum)
{
	if (Answer != -1)
	{
		return;
	}

	SumResult.insert(CurSum);

	for (int i = 0; i < N; i++)
	{
		if (IsVisit[i])
		{
			continue;
		}

		IsVisit[i] = true;
		BT(CurSum + Nums[i]);
		IsVisit[i] = false;
	}
}

int main()
{
	//std::cin >> N;
	N = 1000;

	IsVisit.resize(N, false);
	Nums.resize(N);

	for (int i = 0; i < N; i++)
	{
		Nums[i] = i + 1;
	}

	std::sort(Nums.begin(), Nums.end());
	
	BT(0);

	return 0;
}