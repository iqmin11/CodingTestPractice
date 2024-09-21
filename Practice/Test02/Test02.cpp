//문제 주소 : 

#include <iostream>
#include <vector>

struct Question
{
public:
	Question(const std::string& Str, int a, int b)
		: QStr(Str), a(a), b(b)
	{

	}

	std::string QStr;
	int a;
	int b;
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n = 7;
	std::vector<Question> Qs = 
	{
		{"roga", 1, 1},
		{"rase", 0, 1},
		{"poru", 0, 1},
		{"gipa", 0, 1},
		{"dego", 3, 0},
		{"bego", 3, 0},
		{"nego", 3, 0}
	};

	std::string Odd = "bdgnprst";
	std::string Even = "aeiou";

	std::string CurStr = "xxxx";
	std::string Answer = "";
	int ConditionSatisfiedCount = 0;
	for (int First = 0; First < Odd.size(); First++)
	{
		for (int Second = 0; Second < Even.size(); Second++)
		{
			for (int Third = 0; Third < Odd.size(); Third++)
			{
				if (First == Third)
				{
					continue;
				}

				for (int Fourth = 0; Fourth < Even.size(); Fourth++)
				{
					if (Second == Fourth)
					{
						continue;
					}

					CurStr[0] = Odd[First];
					CurStr[1] = Even[Second];
					CurStr[2] = Odd[Third];
					CurStr[3] = Even[Fourth];
					
					bool IsSuccess = true;

					for (int i = 0; i < n; i++)
					{
						std::string& CheckStr = Qs[i].QStr;
						int a = 0;
						int b = 0;

						for (int j = 0; j < 4; j++)
						{
							if (CheckStr[j] == CurStr[j])
							{
								++a;
								continue;
							}

							if (CheckStr[j] == CurStr[(j + 2) % 4])
							{
								++b;
							}
						}

						if (a != Qs[i].a || b != Qs[i].b)
						{
							IsSuccess = false;
							break;
						}
					}

					if (IsSuccess)
					{
						ConditionSatisfiedCount++;
						if (ConditionSatisfiedCount >= 2)
						{
							std::cout << 'x' << '\n';
							return 0;
						}
						Answer = CurStr;
					}
				}
			}
		}
	}

	if (ConditionSatisfiedCount == 0)
	{
		std::cout << 'x' << '\n';
	}
	else
	{
		std::cout << Answer << '\n';
	}

	return 0;
}