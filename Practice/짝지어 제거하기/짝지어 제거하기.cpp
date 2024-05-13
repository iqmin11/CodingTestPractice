//문제 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/12973

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    std::stack<char> St;

    for (int i = 0; i < s.size(); i++)
    {
        if (St.empty())
        {
            St.push(s[i]);
            continue;
        }

        if (s[i] == St.top())
        {
            St.pop();
        }
        else
        {
            St.push(s[i]);
        }
    }

    int answer = static_cast<int>(St.empty());

    return answer;
}