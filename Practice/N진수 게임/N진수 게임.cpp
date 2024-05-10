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
    //10�������θ� �����ϱ�
    std::vector<char> SaidNum; //Ư�� ��°�� ���ؾ� �ϴ� ����
    SaidNum.push_back('0');

    int Size = p + (m * t);

    //��Ȯ���� ������ ������ �� �����ٴ� ����
    for (int i = 0; i < Size; i++)
    {
        //i�� Ư�� 10���� ���ڰ� �����µ�, �ڸ����� ���� �� ���ڰ� ������ ���������� �޶�����
        //1. ���ڸ� ���ʷ� �ڸ����� ��������

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

    //������ p-1�̰� ������ m�� ���������� t�� ���϶�
    //(p-1) + m * (t - 1);

    int LastIndex = (p - 1) + m * (t - 1);
    for (int i = p - 1; i <= LastIndex; i += m)
    {
        answer.push_back(SaidNum[i]);
    }

    return answer;
}