#include <iostream>

std::pair<bool, int> IsFindStr(const std::string& _DestStr, const std::string& _FindStr, size_t _StartIndex) //반환값은 내가 다음부터 조사해야하는 인덱스, 찾았는지 못찾았는지
{
	size_t DestSize = _DestStr.size();
	size_t FindSize = _FindStr.size();
	size_t RemainSize = DestSize - FindSize;
	if (RemainSize < _StartIndex)
	{
		return std::make_pair(false, -1); //-1이 리턴이면 더이상 조사할 필요 없음
	}

	int count = 0;
	for (size_t i = _StartIndex; i < _StartIndex + FindSize; i++)
	{
		if (_DestStr[i] == _FindStr[count++])
		{
			continue;
		}

		return std::make_pair(false, i - 1); //맞은곳 까지의 인덱스 반환
	}

	return std::make_pair(true, _StartIndex + FindSize - 1);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, M;
	std::string Str;
	std::cin >> N >> M;
	
	std::string FindStr;
	FindStr.resize(2 * N + 1);
	bool Mod = false;
	for (size_t i = 0; i < FindStr.size(); i++)
	{
		if (Mod) // 짝수
		{
			FindStr[i] = 'O';
		}
		else // 홀수
		{
			FindStr[i] = 'I';
		}
		Mod = !Mod;
	}

	Str.resize(M);
	std::cin >> Str;
	bool IsFind = false;

	int Answer = 0;

	for (size_t i = 0; i < M; i++)
	{
		if (IsFind)
		{
			//이전에 한번 찾았으면 다음에는 2개씩만 체크하면됨
			//다음 두개가 OI이면 +1
			//II OO IO면 그 다음 인덱스부터 훑기 시작하면됨
			if (i + 1 >= M)
			{
				break;
			}

			if (Str[i] == 'O' && Str[i + 1] == 'I')
			{
				IsFind = true;
				++Answer;
				i += 1;
			}
			else if(Str[i] == 'O' && Str[i + 1] == 'O')
			{
				IsFind = false;
				i += 1;
			}
			else if(Str[i] == 'I' && Str[i + 1] == 'I')
			{
				IsFind = false;
			}
			else if(Str[i] == 'I' && Str[i + 1] == 'O')
			{
				std::pair<bool, int> Result = IsFindStr(Str, FindStr, i); // 가장 기본적으로 다 훑는 로직
				IsFind = Result.first;

				if (Result.second == -1)
				{
					break;
				}

				i = Result.second;

				if (IsFind)
				{
					++Answer;
				}
			}
		}
		else
		{
			if (Str[i] != 'I')
			{
				continue;
			}

			std::pair<bool, int> Result = IsFindStr(Str, FindStr, i); // 가장 기본적으로 다 훑는 로직
			IsFind = Result.first;

			if (Result.second == -1)
			{
				break;
			}

			i = Result.second;

			if (IsFind)
			{
				++Answer;
			}
		}
	}

	std::cout << Answer;	
}