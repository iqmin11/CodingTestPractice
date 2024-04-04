//https://school.programmers.co.kr/learn/courses/30/lessons/42746

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers)
{
    std::sort(numbers.begin(), numbers.end(), [](int _left, int _right)
        {
            std::string Left = std::to_string(_left);
            std::string Right = std::to_string(_right);

            std::string LeftRight = Left + Right;
            std::string RightLeft = Right + Left;

            return LeftRight > RightLeft;
        });

    string answer = "";

    for (int i = 0; i < numbers.size(); ++i)
    {
        answer += std::to_string(numbers[i]);
    }

    if (answer.front() == '0')
    {
        return "0";
    }

    return answer;
}