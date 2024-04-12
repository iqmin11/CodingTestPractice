//https://school.programmers.co.kr/learn/courses/30/lessons/12905

#include <iostream>
#include<vector>
using namespace std;

int dx[] = { -1,0,-1 };
int dy[] = { -1,-1,0 };


int solution(vector<vector<int>> board)
{
    int answer = INT32_MIN;

    for (size_t y = 0; y < board.size(); y++)
    {
        for (size_t x = 0; x < board[y].size(); x++)
        {
            if (board[y][x] == 0)
            {
                continue;
            }

            if (0 < x && 0 < y)
            {
                board[y][x] = std::min(board[y - 1][x - 1], std::min(board[y - 1][x], board[y][x - 1])) + 1;
            }

            answer = std::max(board[y][x], answer);
        }
    }

    return answer * answer;
}

int main()
{
    solution({ { 0, 0, 1, 1 }, { 1, 1, 1, 1 }, { 1, 1, 1, 1 }, { 0, 0, 1, 0 } });
}