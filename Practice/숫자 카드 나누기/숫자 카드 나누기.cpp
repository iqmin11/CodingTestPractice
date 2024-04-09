//https://school.programmers.co.kr/learn/courses/30/lessons/135807#

#include <string>
#include <vector>

using namespace std;

int GCD(int left, int right)
{
    int Mod = left % right;
    if (Mod == 0)
    {
        return right;
    }
    return GCD(right, Mod);
}

bool Check(const vector<int>& _Arr, int _GCDValue)
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
    int Answer = INT32_MIN;
    int A_GCDValue = arrayA[0];
    for (int i = 1; i < arrayA.size(); ++i)
    {
        A_GCDValue = GCD(A_GCDValue, arrayA[i]);
    }

    if (A_GCDValue != 1)
    {
        if (Check(arrayB, A_GCDValue))
        {
            Answer = A_GCDValue;
        }
    }

    int B_GCDValue = arrayB[0];
    for (int i = 1; i < arrayB.size(); ++i)
    {
        B_GCDValue = GCD(B_GCDValue, arrayB[i]);
    }

    if (B_GCDValue != 1)
    {
        if (Check(arrayA, B_GCDValue))
        {
            Answer = std::max(B_GCDValue, Answer);
        }
    }

    if (Answer == INT32_MIN)
    {
        Answer = 0;
    }

    return Answer;
}

int main()
{
    solution({ 10, 17 }, { 5, 20 });
}