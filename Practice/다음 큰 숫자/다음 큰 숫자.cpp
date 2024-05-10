//문제 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/12911

#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(int n)
{
    //2진수 배열로 만들기
    std::vector<char> Binary;
    Binary.push_back('0');
    int CurNum = n;
    std::stack<char> St;

    while (CurNum != 0)
    {
        St.push(CurNum % 2 + '0');
        CurNum /= 2;
    }

    while (!St.empty())
    {
        Binary.push_back(St.top());
        St.pop();
    }

    std::next_permutation(Binary.begin(), Binary.end());

    int MostPowNum = Binary.size() - 1;
    int answer = 0;

    //다시 10진수로 만들기
    for (auto i : Binary)
    {
        int N = std::pow(2, MostPowNum--);
        answer += N * (i - '0');
    }

    return answer;
}