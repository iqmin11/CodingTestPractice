//문제 주소 : https://www.acmicpc.net/problem/9549

#include <iostream>
#include <string>

bool BS(const std::string& Prev, const std::string& Next)
{
	int Right = 0;
	int WindowSize = Prev.size();
	int AsciiTable[26] = {};
	for (int i = 0; i < Prev.size(); i++)
	{
		AsciiTable[Prev[i] - 'a']++;
	}

	for (int Left = 0; Left < Next.size(); Left++)
	{
		while (WindowSize > Right - Left && Right < Next.size())
		{
			AsciiTable[Next[Right] - 'a']--;
			Right++;
		}

		bool IsAllZero = false;

		if (WindowSize == Right - Left)
		{
			IsAllZero = true;

			for (int i = 0; i < 26; i++)
			{
				if (AsciiTable[i] != 0)
				{
					IsAllZero = false;
					break;
				}
			}
		}

		if (IsAllZero)
		{
			return true;
		}

		AsciiTable[Next[Left] - 'a']++;
	}

	return false;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int T;
	std::cin >> T;
	for (int t = 0; t < T; t++)
	{
		std::string Prev, Next;
		std::cin >> Next >> Prev;

		if (BS(Prev, Next))
		{
			std::cout << "YES" << '\n';
		}
		else
		{
			std::cout << "NO" << '\n';
		}
	}

	return 0;
}