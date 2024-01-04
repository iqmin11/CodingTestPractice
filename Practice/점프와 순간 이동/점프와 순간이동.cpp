#include <iostream>
using namespace std;

int solution(int n)
{
    int N = n;
    int ans = 0;

    while (N != 0)
    {
        if (N % 2 == 0)
        {
            N /= 2;
        }
        else
        {
            N -= 1;
            ans++;
        }
    }

    return ans;
}