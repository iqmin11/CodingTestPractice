#include <iostream>
#include <string>
#include <vector>

std::string solution(std::vector<std::string> _Ex)
{
	std::string Result = std::string();
	size_t MaxLength = 0;

	for (size_t i = 0; i < _Ex.size(); i++)
	{
		size_t Compair = _Ex[i].length();

		if (MaxLength < Compair)
		{
			MaxLength = Compair;
		}
	}

	for (size_t x = 0; x < MaxLength; x++)
	{
		for (size_t y = 0; y < _Ex.size(); y++)
		{
			if (_Ex[y].length() <= x) //이부분이 헷갈림, <로 하면 \0 이 들어가는 애들도 있어서 .... 이건 얘기를 해보자 length에 대해서 등
			{
				continue;
			}

			Result += _Ex[y][x];
		}
	}

	return Result;
}

int main()
{
	std::vector<std::string> Exemple = std::vector<std::string>();
	
	Exemple.reserve(5);
	for (size_t i = 0; i < Exemple.capacity(); i++)
	{
		Exemple.emplace_back();
	}

	std::cin >> Exemple[0];
	std::cin >> Exemple[1];
	std::cin >> Exemple[2];
	std::cin >> Exemple[3];
	std::cin >> Exemple[4];

	std::string Answer = solution(Exemple);

	std::cout << Answer;

	return 0;
}