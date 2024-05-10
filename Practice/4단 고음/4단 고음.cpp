//문제 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/1831

#include <iostream>
#include <stack>

long long Count = 0;
long long Score = 3;
void BT(long long PlusCount, long long Target)
{
    if (Score == Target && PlusCount == 0)
    {
        Count++;
        return;
    }

    if (Score > Target)
    {
        return;
    }

    if ((Score > Target / 3) && Target - Score > PlusCount)
    {
        return;
    }

    for (int i = 0; i < 2; i++)
    {
        if (i == 0)
        {
            Score *= 3;
            BT(PlusCount + 2, Target);
            Score /= 3;
        }
        else if (i == 1 && PlusCount > 0)
        {
            Score += 1;
            BT(PlusCount - 1, Target);
            Score -= 1;
        }

    }

}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n)
{
    Score = 3;
    Count = 0;

    BT(2, n);

    return Count;
}



int main()
{
    solution(INT32_MAX);

	return 0;
}