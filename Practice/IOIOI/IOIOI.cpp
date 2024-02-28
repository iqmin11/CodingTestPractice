#include <iostream>

std::pair<bool, int> IsFindStr(const std::string& _DestStr, const std::string& _FindStr, size_t _StartIndex) //��ȯ���� ���� �������� �����ؾ��ϴ� �ε���, ã�Ҵ��� ��ã�Ҵ���
{
	size_t DestSize = _DestStr.size();
	size_t FindSize = _FindStr.size();
	size_t RemainSize = DestSize - FindSize;
	if (RemainSize < _StartIndex)
	{
		return std::make_pair(false, -1); //-1�� �����̸� ���̻� ������ �ʿ� ����
	}

	int count = 0;
	for (size_t i = _StartIndex; i < _StartIndex + FindSize; i++)
	{
		if (_DestStr[i] == _FindStr[count++])
		{
			continue;
		}

		return std::make_pair(false, i - 1); //������ ������ �ε��� ��ȯ
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
		if (Mod) // ¦��
		{
			FindStr[i] = 'O';
		}
		else // Ȧ��
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
			//������ �ѹ� ã������ �������� 2������ üũ�ϸ��
			//���� �ΰ��� OI�̸� +1
			//II OO IO�� �� ���� �ε������� �ȱ� �����ϸ��
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
				std::pair<bool, int> Result = IsFindStr(Str, FindStr, i); // ���� �⺻������ �� �ȴ� ����
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

			std::pair<bool, int> Result = IsFindStr(Str, FindStr, i); // ���� �⺻������ �� �ȴ� ����
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