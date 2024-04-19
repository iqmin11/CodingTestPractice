//https://school.programmers.co.kr/learn/courses/30/lessons/42883

#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

string solution(string number, int k)
{
    int ResultCount = number.size() - k;

    std::deque<char> dq;
    for (int i = 0; i < number.size();)
    {
        if (!dq.empty())
        {
            if (dq.back() < number[i] && k > 0)
            {
                k--;
                dq.pop_back();
                continue;
            }
        }
        dq.push_back(number[i++]);
    }

    string answer;

    for (int i = 0; i < ResultCount; i++)
    {
        answer.push_back(dq[i]);
    }

    return answer;
}