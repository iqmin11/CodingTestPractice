//문제 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/12939

#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s)
{
    int MaxValue = INT32_MIN;
    int MinValue = INT32_MAX;

    std::stringstream Buffer(s);
    int CurValue;
    while (Buffer >> CurValue)
    {
        MaxValue = std::max(MaxValue, CurValue);
        MinValue = std::min(MinValue, CurValue);
    }

    std::string MinStr = std::to_string(MinValue);
    std::string MaxStr = std::to_string(MaxValue);

    string answer = MinStr + " " + MaxStr;
    return answer;
}