#include <iostream>
#include <set>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;
	std::multiset<int> Nums;

	int Size = 0;
	std::multiset<int>::iterator MidIter;
	int MidValue = 0;
	std::vector<int> Answer;
	Answer.reserve(N);
	
	{
		int InsertNum;
		std::cin >> InsertNum;
		Nums.insert(InsertNum);
		++Size;
		MidIter = Nums.begin();
		MidValue = *MidIter;
		Answer.push_back(MidValue);
	}

	for (size_t i = 0; i < N - 1; i++)
	{
		int InsertNum;
		std::cin >> InsertNum;
		Nums.insert(InsertNum);
		
		++Size;

		if (Size % 2 == 1)
		{
			if(MidValue <= InsertNum)
			{
				++MidIter;

				MidValue = *MidIter;
			}
		}
		else
		{
			if (MidValue > InsertNum)
			{
				--MidIter;
				MidValue = *MidIter;
			}
		}

		Answer.push_back(MidValue);
	}


	for (size_t i = 0; i < N; i++)
	{
		std::cout << Answer[i] << "\n";
	}

	return 0;
}