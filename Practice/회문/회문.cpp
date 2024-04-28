//문제 주소 : https://www.acmicpc.net/problem/17609

#include <iostream>
#include <vector>

bool CheckPopPosition(const std::string& Data, int LeftIndex, int Rightindex)
{
	bool Check1 = Data[LeftIndex + 1] == Data[Rightindex]; // 앞을 빼야함
	bool Check2 = Data[LeftIndex] == Data[Rightindex - 1]; // 뒤를 빼야함

	if (Check1 && Check2)
	{
		return CheckPopPosition(Data, LeftIndex + 1, Rightindex - 1);
	}
	
	return Check1;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int TestCase;

	std::cin >> TestCase;

	std::vector<int> Answers;
	Answers.reserve(TestCase);

	for (int T = 0; T < TestCase; T++)
	{
		std::string Data;
		std::cin >> Data;

		int DeleteCount = 1;
		int Answer = 0;

		int Left = 0;
		int Right = static_cast<int>(Data.size()) - 1;

		while (Left < Right)
		{
			if (Data[Left] == Data[Right] && Right - Left > 0)
			{
				Left++;
				Right--;
			}
			else if(DeleteCount > 0)
			{
				Answer = 1;

				if (CheckPopPosition(Data, Left, Right)) // 앞이면 true 뒤면 false
				{
					Left++;
				}
				else
				{
					Right--;
				}
				
				DeleteCount--;
			}
			else
			{
				Answer = 2;
				break;
			}
		}

		Answers.push_back(Answer);
	}

	for (size_t i = 0; i < Answers.size(); i++)
	{
		std::cout << Answers[i] << '\n';
	}

	return 0;
}