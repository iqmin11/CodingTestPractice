//���� �ּ� : https://school.programmers.co.kr/learn/courses/30/lessons/12929#

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//DP����

int DP[15] = { 1, }; //DP[a] = b a���� ��ȣ ���� ������, ���� �� �ִ� �ùٸ� ��ȣ �� 

int solution(int n)
{
    DP[1] = 1;
    for (int i = 2; i <= 14; i++)
    {
        for (int j = 0; j < i; j++)
        {
            DP[i] += DP[j] * DP[(i - 1) - j];
        }
    }

    return DP[n];
}

//1 ()
//
//2 (())
//()()
//
//3 ((())) / (()())
//(())()
//()(()) / ()()()
//
//4 (((()))) / ((()())) / ((())()) / (()(())) / (()()()) / DP[3] * DP[0]
//((()))() / (()())() / DP[2] * DP[1]
//(())()() / (())(()) / DP[1] * DP[2];
//()((())) / ()(()()) / ()(())() / ()()(()) / ()()()() DP[0] * DP[3]


