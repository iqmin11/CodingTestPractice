#include <string>
#include <vector>

// 조건 1. 숫자의 2진수 표현의 자릿수가 2^n-1개 또는 2^n-2개일것
// 조건 2-1. 2^n-1개일경우 짝수번째 자릿수가 1이어야 함 맨앞은 1고정, 짝수번째 1고정, 나머지는 상관없음
// 조건 2-2. 2^n-2개일경우 홀수번째 자릿수가 1이어야 함 나머지 수는 상관없음 

std::string IntToBinStr(long long _Value)
{
	std::string result = "\0";
	while (_Value > 0)
	{
		if (_Value % 2 == 1)
		{
			result = "1" + result;
		}
		else
		{
			result = "0" + result;
		}
		_Value >>= 1;
	}

	return result;
}

std::vector<int> solution(std::vector <long long> _numbers)
{
    std::vector<int> answer = std::vector<int>();
	answer.resize(_numbers.size());

	for (size_t i = 0; i < _numbers.size(); i++)
	{
		std::string BinStr = IntToBinStr(_numbers[i]);
		size_t ConfirmLenth = BinStr.length();
		bool Check0 = true; // 길이가 2^n-1일 경우
		bool Check1 = true; // 길이가 2^n-2일 경우

		{
			size_t a = ConfirmLenth + 1;
			while (a % 2 == 0)
			{
				a /= 2;
			}

			if (a > 1)
			{
				Check0 = false;
			}

			size_t b = ConfirmLenth + 2;

			while (b % 2 == 0)
			{
				b /= 2;
			}

			if (b > 1)
			{
				Check1 = false;
			}
		}

		
		if (Check0)
		{
			answer[i] = 1;
			for (size_t j = 0; j < BinStr.length() / 2; j++)
			{
				if (BinStr[2 * j + 1] != '1') // 홀수 인덱스가 1이 아니면
				{
					answer[i] = 0;
					break;
				}
			}
		}
		else if (Check1)
		{
			answer[i] = 1;
			for (size_t j = 0; j < BinStr.length() / 2; j++)
			{
				if (BinStr[2 * j] != '1') // 짝수 인덱스가 1이 아니면
				{
					answer[i] = 0;
					break;
				}
			}
		}
		else
		{
			answer[i] = 0;
		}
	}

    return answer;
}

int main()
{
	std::vector <long long> Ex({ 128 });
	std::vector<int> answer = solution(Ex);
	return 0;
}