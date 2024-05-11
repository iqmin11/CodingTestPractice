//문제 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/17679

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

    while (IsCrushBlock) // 부서지는 블록이 없었으면 탈출
    {
        IsCrushBlock = false;
        std::vector<std::string> Buffer = board;
        //검사하고
        //1. 검사는 오리지날에서
        //최대 x y라고 하면 2*2검사는 x-1 y-1까지
        //n이 x사이즈 m이 y사이즈
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

                if (IsSame) // 2*2 블록이 같음
                {
                    IsCrushBlock = true;
                    //2. 지우는 것은 버퍼에서
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

        //떨군다
        for (int x = 0; x < n; ++x)
        {
            std::queue<char> RePush;
            for (int y = m - 1; y >= 0; --y) // 아래서부터 체크
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

        //버퍼를 원본으로
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