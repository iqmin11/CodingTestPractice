#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

char IntToStr(int Num)
{
    if (Num < 10)
    {
        return static_cast<char>(Num + '0');
    }
    else
    {
        return static_cast<char>(Num - 10 + 'A');
    }
}

string solution(int n, int t, int m, int p)
{
    //10진법으로만 생각하기
    std::vector<char> SaidNum; //특정 번째에 말해야 하는 숫자
    SaidNum.push_back('0');

    int Size = p + (m * t);

    //정확하진 않지만 무조건 이 값보다는 작음
    for (int i = 0; i < Size; i++)
    {
        //i는 특정 10진법 숫자가 나오는데, 자릿수에 따라서 한 숫자가 몇명까지 말해지는지 달라져요
        //1. 숫자를 차례로 자릿수로 나눠야함

        int CurNumber = i;
        std::stack<int> St;
        while (CurNumber != 0)
        {
            St.push(CurNumber % n);
            CurNumber /= n;
        }

        while (!St.empty())
        {
            SaidNum.push_back(IntToStr(St.top()));
            St.pop();
        }
    }

    string answer = "";

    //초항이 p-1이고 공차가 m인 등차수열을 t항 구하라
    //(p-1) + m * (t - 1);

    int LastIndex = (p - 1) + m * (t - 1);
    for (int i = p - 1; i <= LastIndex; i += m)
    {
        answer.push_back(SaidNum[i]);
    }

    return answer;
}