//���� �ּ� : https://school.programmers.co.kr/learn/courses/30/lessons/12985

#include <iostream>
#include <cmath>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    if (a > b)
    {
        std::swap(a, b); //������ ������Ű��
    }

    //�̵尪�� ���ϰ� ���������� üũ
    int Left = 1; //������ 1 
    int Right = n; //������ n
    int WholeRound = static_cast<int>(std::log2(n));

    while (WholeRound != 0)
    {
        int mid = (Left + Right - 1) / 2; //8�̸� 4�� ����

        if (a <= mid && b > mid) //������ ���� �ٸ��ٸ�
        {
            return WholeRound;
        }

        //���ٸ� �� �����ڰ� �����ִ� ���� ������ �ٲٰ�
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