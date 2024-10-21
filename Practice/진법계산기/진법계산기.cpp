//문제 주소 : 

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

std::string Decimal2Other(long long Decimal, int Other)
{
	bool IsNegative = Decimal < 0;
	std::string OtherValue;
	Decimal = std::abs(Decimal);

	while (Decimal > 0)
	{
		OtherValue.push_back((Decimal % Other) + '0');
		Decimal /= Other;
	}

	if (IsNegative)
	{
		OtherValue.push_back('-');
	}
	
	std::reverse(OtherValue.begin(), OtherValue.end());
	return OtherValue;
}

long long Other2Decimal(const std::string& OtherValue, int Other)
{
	return std::stoll(OtherValue, nullptr, Other);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::string TestBinary = Decimal2Other(111, 2);
	std::string TestOctal = Decimal2Other(111, 8);
	std::string TestDecimal = Decimal2Other(111, 10);

	long long TestBinary2Decimal = Other2Decimal(TestBinary, 2);
	long long TestOctal2Decimal = Other2Decimal(TestOctal, 8);
	long long TestDecimal2Decimal = Other2Decimal(TestDecimal, 10);
	
	return 0;
}