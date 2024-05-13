//문제 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/12985

#include <iostream>
#include <cmath>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    if (a > b)
    {
        std::swap(a, b); //순번을 고정시키자
    }

    //미드값을 구하고 같은조인지 체크
    int Left = 1; //시작은 1 
    int Right = n; //시작은 n
    int WholeRound = static_cast<int>(std::log2(n));

    while (WholeRound != 0)
    {
        int mid = (Left + Right - 1) / 2; //8이면 4가 나옴

        if (a <= mid && b > mid) //서로의 조가 다르다면
        {
            return WholeRound;
        }

        //같다면 두 참가자가 속해있는 조로 범위를 바꾸고
        if (a > mid)
        {
            Left = mid + 1;
        }
        else
        {
            Right = mid;
        }

        --WholeRound;
    }

    return 0;
}