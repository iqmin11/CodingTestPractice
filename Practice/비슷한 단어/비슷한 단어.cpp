//문제 주소 : https://www.acmicpc.net/problem/2607

#include <iostream>
#include <vector>

std::vector<int> AsciiTableInit(const std::string& Str)
{
	std::vector<int> result;
	result.resize(26, 0);

	for (int i = 0; i < Str.size(); i++)
	{
		++result[Str[i] - 'A'];
	}

	return result;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;

	std::cin >> N;

	std::vector<std::vector<int>> Words;
	Words.resize(N);

	for (int i = 0; i < N; i++)
	{
		std::string temp;
		std::cin >> temp;
		Words[i] = AsciiTableInit(temp);
	}

	const std::vector<int>& CompWord = Words[0];

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			Words[i][j] = CompWord[j] - Words[i][j];
		}
	}

	std::vector<bool> IsSimilar;
	IsSimilar.resize(N, true);

	//같은 구성인가? = 모든 글자의 변화량이 0
	
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (Words[i][j])
			{
				IsSimilar[i] = false;
				break;
			}
		}
	}

	//하나를 빼거나 더하는 과정을 통해 같은 구성으로 만들 수 있는가? 딱 하나의 글자의 변화량만 1

	for (int i = 1; i < N; i++)
	{
		if (IsSimilar[i])
		{
			continue;
		}

		IsSimilar[i] = true;
		int OneCount = 1;

		for (int j = 0; j < 26; j++)
		{
			if (OneCount < 0)
			{
				IsSimilar[i] = false;
				break;
			}

			if (std::abs(Words[i][j]) == 1)
			{
				OneCount--;
			}
			else if(Words[i][j] != 0)
			{
				IsSimilar[i] = false;
				break;
			}
		}
	}

	//글자 하나를 바꾸는 과정을 통해 같은 구성으로 만들 수 있는가? -1하나 1하나

	for (int i = 1; i < N; i++)
	{
		if (IsSimilar[i])
		{
			continue;
		}

		IsSimilar[i] = true;
		int PositiveOneCount = 1;
		int NegativeOneCount = 1;

		for (int j = 0; j < 26; j++)
		{
			if (PositiveOneCount < 0 || NegativeOneCount < 0)
			{
				IsSimilar[i] = false;
				break;
			}

			if (Words[i][j] == 1)
			{
				PositiveOneCount--;
			}
			else if(Words[i][j] == -1)
			{
				NegativeOneCount--;
			}
			else if (Words[i][j] != 0)
			{
				IsSimilar[i] = false;
				break;
			}
		}
	}

	int Answer = 0;

	for (int i = 1; i < N; i++)
	{
		if (IsSimilar[i])
		{
			Answer++;
		}
	}

	std::cout << Answer;

	return 0;
}