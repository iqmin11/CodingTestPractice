//문제 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/12909

#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int LeftCount = 0;
    int RightCount = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            ++LeftCount;
        }
        else
        {
            ++RightCount;
        }

        if (RightCount > LeftCount)
        {
            answer = false;
            break;
        }
    }

    if (LeftCount != RightCount)
    {
        answer = false;
    }

    return answer;
}