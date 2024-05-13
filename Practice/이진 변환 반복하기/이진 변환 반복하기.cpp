//문제 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/70129

#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(string s)
{
    int RepeatCount = 0;
    int ZeroCount = 0;

    while (s != "1")
    {
        ++RepeatCount;
        int OneCount = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
            {
                OneCount++;
            }
            else
            {
                ZeroCount++;
            }
        }

        std::stack<int> St;
        while (OneCount != 0)
        {
            St.push(OneCount % 2);
            OneCount /= 2;
        }

        s.clear();
        while (!St.empty())
        {
            s.push_back(St.top() + '0');
            St.pop();
        }
    }

    vector<int> answer;
    answer.push_back(RepeatCount);
    answer.push_back(ZeroCount);
    return answer;
}