//https://school.programmers.co.kr/learn/courses/30/lessons/160585

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

std::unordered_map<std::string, bool> IsVisit;
std::string Dest;
bool Result = false;

bool IsEnd(const std::string& Board)
{
    if (Board[4] != '.')
    {
        if (Board[0] == Board[4] && Board[4] == Board[8])
        {
            return true;
        }

        if (Board[2] == Board[4] && Board[4] == Board[6])
        {
            return true;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (Board[i] != '.')
        {
            if (Board[i] == Board[i + 3] && Board[i + 3] == Board[i + 6])
            {
                return true;
            }
        }

        if (Board[3 * i] != '.')
        {
            if (Board[3 * i] == Board[3 * i + 1] && Board[3 * i + 1] == Board[3 * i + 2])
            {
                return true;
            }
        }
    }

    return false;
}

void DFS(std::string& CurIndex, bool Turn)
{
    bool CurTurn = !Turn; // First : true; Second : false;
    IsVisit[CurIndex] = true;

    if (Dest == CurIndex || Result == true)
    {
        Result = true;
        return;
    }

    if (IsEnd(CurIndex))
    {
        return;
    }

    for (int i = 0; i < 9; ++i)
    {
        if (CurIndex[i] != '.')
        {
            continue;
        }

        char Shape = 0;
        if (CurTurn)
        {
            Shape = 'O';
        }
        else
        {
            Shape = 'X';
        }

        std::string CheckIndex = CurIndex;
        CheckIndex[i] = Shape;

        DFS(CheckIndex, CurTurn);
    }
}

int solution(vector<string> board)
{
    for (auto& i : board)
    {
        Dest += i;
    }

    std::string Start = ".........";
    DFS(Start, false);

    int answer = static_cast<int>(Result);
    return answer;
}

int main()
{
    solution({ "OOO", "...", "XXX" });
}