//문제 주소 : https://www.acmicpc.net/problem/9241

#include <iostream>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::string Before, After;
	std::cin >> Before >> After;

	std::string* Longer = &Before;
	std::string* Shorter = &After;

	if (Longer->size() < Shorter->size())
	{
		std::swap(Longer, Shorter);
	}

	std::vector<bool> ShorterErase(Shorter->size());
	int Index = 0;

	int Answer = static_cast<int>(After.size());
	std::string::iterator CurLongIter = Longer->begin();
	for (std::string::iterator CurShortIter = Shorter->begin(); CurShortIter != Shorter->end(); ++CurShortIter)
	{
		if (*CurShortIter != *CurLongIter)
		{
			break;
		}

		--Answer;
		++CurLongIter;
		ShorterErase[Index++] = true;
	}

	std::string::reverse_iterator CurLongRIter = Longer->rbegin();
	Index = static_cast<int>(Shorter->size()) - 1;
	for (std::string::reverse_iterator CurShortRIter = Shorter->rbegin(); CurShortRIter != Shorter->rend(); ++CurShortRIter)
	{
		if (*CurShortRIter != *CurLongRIter)
		{
			break;
		}

		if (ShorterErase[Index--])
		{
			break;
		}

		--Answer;
		++CurLongRIter;
	}

	std::cout << Answer;

	return 0;
}