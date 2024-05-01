//문제 주소 : https://www.acmicpc.net/problem/20310

#include <iostream>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::string Str;
	std::cin >> Str;

	std::string StrCount = Str;

	std::sort(StrCount.begin(), StrCount.end());
	std::string::iterator ZeroBegin = StrCount.begin();
	std::string::iterator ZeroEnd = std::upper_bound(StrCount.begin(), StrCount.end(), '0');
	int DeleteZeroSize = (ZeroEnd - ZeroBegin) / 2;

	std::string::iterator OneBegin = std::lower_bound(StrCount.begin(), StrCount.end(), '1');
	std::string::iterator OneEnd = StrCount.end();
	int DeleteOneSize = (OneEnd - OneBegin) / 2;

	for (int i = 0; i < Str.size(); i++)
	{
		if (Str[i] == '1')
		{
			if (DeleteOneSize-- > 0)
			{
				Str[i] = 'D';
			}
			else
			{
				break;
			}
		}
	}

	for (int i = Str.size() - 1; i >= 0; i--)
	{
		if (Str[i] == '0')
		{
			if (DeleteZeroSize-- > 0)
			{
				Str[i] = 'D';
			}
			else
			{
				break;
			}
		}
	}

	for (int i = 0; i < Str.size(); i++)
	{
		if (Str[i] == 'D')
		{
			continue;
		}

		std::cout << Str[i];
	}

	return 0;
}