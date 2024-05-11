//���� �ּ� : https://school.programmers.co.kr/learn/courses/30/lessons/17679

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int dx[] = { 1, 1, 0 };
int dy[] = { 0, 1, 1 };

int solution(int m, int n, vector<string> board)
{
    bool IsCrushBlock = true;

    while (IsCrushBlock) // �μ����� ����� �������� Ż��
    {
        IsCrushBlock = false;
        std::vector<std::string> Buffer = board;
        //�˻��ϰ�
        //1. �˻�� ������������
        //�ִ� x y��� �ϸ� 2*2�˻�� x-1 y-1����
        //n�� x������ m�� y������
        for (int y = 0; y < m - 1; ++y)
        {
            for (int x = 0; x < n - 1; ++x)
            {
                if (board[y][x] == '0')
                {
                    continue;
                }

                int IsSame = true;

                for (int k = 0; k < 3; ++k)
                {
                    int CheckX = x + dx[k];
                    int CheckY = y + dy[k];

                    if (board[CheckY][CheckX] != board[y][x])
                    {
                        IsSame = false;
                        break;
                    }
                }

                if (IsSame) // 2*2 ����� ����
                {
                    IsCrushBlock = true;
                    //2. ����� ���� ���ۿ���
                    Buffer[y][x] = '0';
                    for (int k = 0; k < 3; ++k)
                    {
                        int CheckX = x + dx[k];
                        int CheckY = y + dy[k];

                        Buffer[CheckY][CheckX] = '0';
                    }
                }
            }
        }

        //������
        for (int x = 0; x < n; ++x)
        {
            std::queue<char> RePush;
            for (int y = m - 1; y >= 0; --y) // �Ʒ������� üũ
            {
                if (Buffer[y][x] == '0')
                {
                    continue;
                }
                RePush.push(Buffer[y][x]);
            }

            for (int y = m - 1; y >= 0; --y)
            {
                if (RePush.empty())
                {
                    Buffer[y][x] = '0';
                    continue;
                }
                Buffer[y][x] = RePush.front();
                RePush.pop();
            }
        }

        //���۸� ��������
        board = Buffer;
    }

    int answer = 0;

    for (int y = 0; y < m; ++y)
    {
        for (int x = 0; x < n; ++x)
        {
            if (board[y][x] == '0')
            {
                answer++;
            }
        }
    }

    return answer;
}