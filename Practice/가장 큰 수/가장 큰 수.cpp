#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

string solution(vector<int> numbers)
{
    std::sort(numbers.begin(), numbers.end(), [](int _left, int _right)
        {
            int LeftLog = static_cast<int>(std::log10(_left));
            int RightLog = static_cast<int>(std::log10(_right));
            int Differ = std::abs(RightLog - LeftLog);

            for (int i = 0; i < Differ; ++i)
            {
                if (LeftLog < RightLog)
                {
                    _left *= 10;
                }
                else
                {
                    _right *= 10;
                }
            }

            if (_left == _right)
            {
                return LeftLog < RightLog;
            }

            return _left > _right;
        });

    string answer = "";

    for (int i = 0; i < numbers.size(); ++i)
    {
        answer += std::to_string(numbers[i]);
    }

    return answer;
}