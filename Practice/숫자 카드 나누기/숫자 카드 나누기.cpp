//https://school.programmers.co.kr/learn/courses/30/lessons/135807#

#include <string>
#include <vector>

using namespace std;

long long GCD(long long left, long long right)
{
    long long Mod = left % right;
    if (Mod == 0)
    {
        return right;
    }
    return GCD(right, Mod);
}

bool Check(const vector<int>& _Arr, long long _GCDValue)
{
    for (auto& i : _Arr)
    {
        if (i % _GCDValue == 0)
        {
            return false;
        }
    }
    return true;
}

int solution(vector<int> arrayA, vector<int> arrayB)
{
    long long A_GCDValue = arrayA[0];
    for (int i = 1; i < arrayA.size(); ++i)
    {
        A_GCDValue = GCD(A_GCDValue, arrayA[1]);
    }

    long long B_GCDValue = arrayB[0];
    for (int i = 1; i < arrayB.size(); ++i)
    {
        B_GCDValue = GCD(B_GCDValue, arrayB[1]);
    }

    bool A = false;
    bool B = false;

    if (A_GCDValue != 1)
    {
        A = Check(arrayB, A_GCDValue);
    }

    if (B_GCDValue != 1)
    {
        B = Check(arrayA, B_GCDValue);
    }

    if (A && B)
    {
        if (A_GCDValue > B_GCDValue)
        {
            return A_GCDValue;
        }
        return B_GCDValue;
    }

    if (A || B)
    {
        if (A)
        {
            return A_GCDValue;
        }
        return B_GCDValue;
    }

    return 0;
}