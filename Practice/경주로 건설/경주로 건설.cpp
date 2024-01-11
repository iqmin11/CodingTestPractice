#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

std::vector<std::vector<int>> IsVisit; //bool���� int�� �ٲ��ִ°͸����ε� �� 20���� ������� ��������
int RecordCost = 0;
int MinCost = INT32_MAX;
int AtMinCostConerCount = INT32_MAX;
int ConerCount = 0;
int CurMinConerCount = INT32_MAX;
int VirtualMinCostWithConerCount = INT32_MIN;
int VirtualMinCost = 0;
int R, C;

void DebugRender(const std::vector<std::vector<int>> _Board)
{
    std::cout << "////////////////////////////////" << std::endl;
    for (size_t y = 0; y < _Board.size(); y++)
    {
        for (size_t x = 0; x < _Board[y].size(); x++)
        {
            std::cout << _Board[y][x];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

std::vector<std::pair<int, int>> RecordStack;
void DFS(std::pair<int, int> _Start, vector<vector<int>>& _Board)
{
    _Board[_Start.second][_Start.first] = 1;
    RecordStack.emplace_back(_Start);
    DebugRender(_Board);
    int CurAddCost = 0;
    int TempAddCost = 100;
    //�ش� ��ǥ���� ���� �ּҰ� ����

    if (RecordStack.size() >= 3)
    {
        auto CompIter = RecordStack.end();
        CompIter -= 3;
        std::pair<int, int> CompValue = *CompIter;
        if (CompValue.first != _Start.first && CompValue.second != _Start.second) //�ڳ� �˻� �� �߰�
        {
            CurAddCost = 500;
            RecordCost += CurAddCost;
            TempAddCost += CurAddCost;
            ++ConerCount;
        }



        //if (MinCost == VirtualMinCostWithConerCount) //����ȭ1. �ڳ� ī��Ʈ�� ���� ���� �ּ� ����� MinCost���
        //{
        //    if (CurMinConerCount <= ConerCount) //�ڳ� ������ �� �̻��� �ֵ��� �� �ʿ䰡 ����
        //    {
        //        IsVisit[_Start.second][_Start.first] = 0;
        //        RecordStack.pop_back();
        //        RecordCost -= CurAddCost;

        //        if (CurAddCost == 500)
        //        {
        //            --ConerCount;
        //        }
        //        return;
        //    }
        //}

        VirtualMinCostWithConerCount = ConerCount * 500 + ((R - 1 + C - 1) * 100);  //���� �ּ� ��� ���

        //if (MinCost <= RecordCost + (static_cast<int>(RecordStack.size()) - 1) * 100) //����ȭ2 �����ִµ� ���� Mincost ���� �� ����� �̹�
        //{
        //    IsVisit[_Start.second][_Start.first] = 0; //���ʿ䰡 ����
        //    RecordStack.pop_back();
        //    RecordCost -= CurAddCost;

        //    if (CurAddCost == 500)
        //    {
        //        --ConerCount;
        //    }
        //    return;
        //}
    }

    if (_Start.first == C - 1 && _Start.second == R - 1) //�������� �����߰�
    {
        int CompValue = RecordCost + (static_cast<int>(RecordStack.size()) - 1) * 100;
        if (MinCost > CompValue)
        {
            MinCost = CompValue;
            if (VirtualMinCostWithConerCount == MinCost)
            {
                CurMinConerCount = ConerCount;
            }
        }

        _Board[_Start.second][_Start.first] = 0;
        RecordStack.pop_back();
        RecordCost -= CurAddCost;
        if (CurAddCost == 500)
        {
            --ConerCount;
        }
        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        int CheckX = _Start.first + dx[i];
        int CheckY = _Start.second + dy[i];

        if (CheckX < 0 || CheckY < 0 || CheckX >= C || CheckY >= R)
        {
            continue;
        }

        if (_Board[CheckY][CheckX] == 1 || _Board[CheckY][CheckX])
        {
            continue;
        }

        if (RecordStack.size() >= 2)
        {
            int NextCost = (RecordCost + (static_cast<int>(RecordStack.size()) - 1) * 100);
            int NextConerCount = ConerCount;
            auto CompIter = RecordStack.end();
            CompIter -= 2;
            std::pair<int, int> CompValue = *CompIter;
            if (CompValue.first != CheckX && CompValue.second != CheckY)
            {
                NextCost += 500;
                ++NextConerCount;
            }
            else
            {
                NextCost += 100;
            }

            if (MinCost == VirtualMinCostWithConerCount && CurMinConerCount <= NextConerCount)
            {
                continue;
            }

            if (MinCost < NextCost)
            {
                continue;
            }


        }



        DFS(std::make_pair(CheckX, CheckY), _Board);
    }

    _Board[_Start.second][_Start.first] = 0;
    RecordStack.pop_back();
    RecordCost -= CurAddCost;
    if (CurAddCost == 500)
    {
        --ConerCount;
    }
}

//void BFS(std::pair<int, int> _Start, const vector<vector<int>>& _Board)
//{
//    std::queue<std::pair<std::pair<int, int>, int>> q; //��ǥ, ����
//    q.push(_Start)
//
//}

int solution(vector<vector<int>> board)
{
    R = board.size();
    C = board[0].size();

    RecordStack.reserve(R * C);
    VirtualMinCost = ((R - 1 + C - 1) * 100) + 500;

    IsVisit.resize(R);
    for (int i = 0; i < R; ++i)
    {
        IsVisit[i].resize(C, 0);
    }

    DFS(std::make_pair(0, 0), board);

    return MinCost;
}

int main()
{
    std::vector<std::vector<int>> Input;
    Input.resize(25);
    Input.reserve(25);
    Input[0]  = {0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    Input[1]  = {0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    Input[2]  = {0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    Input[3]  = {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    Input[4]  = {1,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    Input[5]  = {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    Input[6]  = {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    Input[7]  = {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    Input[8]  = {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    Input[9]  = {1,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    Input[10] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    Input[11] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    Input[12] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    Input[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    Input[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    Input[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    Input[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1};
    Input[17] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    Input[18] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0};
    Input[19] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0};
    Input[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,1,1};
    Input[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0};
    Input[22] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0};
    Input[23] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1,1};
    Input[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0};

    int answewr = solution(Input);

    return 0;
}

//����ȭ 3
//���� Ƚ���� ���� ���� �ּҰ��� ����
