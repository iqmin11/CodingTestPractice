//문제 주소 : https://www.acmicpc.net/problem/28086

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

long long Octal2Decimal(const std::string& OctalValue)
{
	return std::stoll(OctalValue, nullptr, 8);
}

std::string Decimal2Octal(long long Decimal)
{
	if (Decimal == 0)
	{
		return "0";
	}

	bool IsNegative = Decimal < 0;
	Decimal = std::abs(Decimal);

	std::string Octal;

	while (Decimal > 0)
	{
		Octal.push_back((Decimal % 8) + '0');
		Decimal /= 8;
	}

	if (IsNegative)
	{
		Octal.push_back('-');
	}

	std::reverse(Octal.begin(), Octal.end());
	return Octal;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	//수식
	std::string Input;
	std::cin >> Input;

	std::string Octal0;
	long long Octal0Sign = 1;

	std::string Octal1;
	long long Octal1Sign = 1;

	char Operator = 0;

	long long Offset = 0;
	if (Input[0] == '-')
	{
		Offset = 1;
		Octal0Sign = -1;
	}

	for (; Offset < static_cast<long long>(Input.size()); Offset++)
	{
		if ('0' <= Input[Offset] && Input[Offset] <= '9')
		{
			if (Operator == 0)
			{
				Octal0.push_back(Input[Offset]);
			}
		}
		else
		{
			Operator = Input[Offset];
			break;
		}
	}

	if (Input[++Offset] == '-')
	{
		Offset++;
		Octal1Sign = -1;
	}

	for (; Offset < static_cast<long long>(Input.size()); Offset++)
	{
		Octal1.push_back(Input[Offset]);
	}

	long long DecimalAnswer = 0;
	long long Decimal0 = Octal2Decimal(Octal0) * Octal0Sign;
	long long Decimal1 = Octal2Decimal(Octal1) * Octal1Sign;

	switch (Operator)
	{
	case '+':
		DecimalAnswer = Decimal0 + Decimal1;
		break;
	case '-':
		DecimalAnswer = Decimal0 - Decimal1;
		break;
	case '*':
		DecimalAnswer = Decimal0 * Decimal1;
		break;
	case '/':
		if (Decimal1 == 0.f)
		{
			std::cout << "invalid";
			return 0;
		}

		DecimalAnswer = static_cast<int>(std::floor(static_cast<double>(Decimal0) / static_cast<double>(Decimal1)));

		break;
	default:
		break;
	}

	std::cout << Decimal2Octal(DecimalAnswer);
	return 0;
}