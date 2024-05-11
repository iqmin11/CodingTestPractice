//문제 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/154539

#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers)
{
    //거꾸로 돌면서 넣음
    std::stack<int> St;//크기
    St.push(INT32_MAX);
    vector<int> answer;
    for (int i = numbers.size() - 1; i >= 0; --i)
    {
        while (numbers[i] >= St.top())
        {
            St.pop();
        }

        if (St.top() == INT32_MAX)
        {
            answer.push_back(-1);
        }
        else
        {
            answer.push_back(St.top());
        }

        St.push(numbers[i]);
    }

    std::reverse(answer.begin(), answer.end());
    return answer;
}