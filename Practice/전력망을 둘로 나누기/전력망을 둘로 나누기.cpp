#include <string>
#include <vector>
#include <set>
#include <list>

using namespace std;

std::vector<bool> IsVisit;
std::vector<std::set<int>> Links;

int DFS(int _Start)
{
    int Count = 0;
    if (IsVisit[_Start] == false)
    {
        IsVisit[_Start] = true;
        Count++;
        for (auto& i : Links[_Start])
        {
            Count += DFS(i);
        }
    }
    return Count;
}

int solution(int n, vector<vector<int>> wires)
{
    IsVisit.resize(n, false);
    Links.resize(n);
    std::vector<std::list<int>> DFS_Result;
    DFS_Result.resize(n);
    int MinDiffer = INT32_MAX;
    int exeption = 0;

    while (exeption < n) // ������ �� ��������� ���ž�
    {
        for (int i = 0; i < wires.size(); i++)
        {
            //���� ����
            if (i == exeption)
            {
                continue;
            }
            //���� ���� ä�� �濬��
            Links[wires[i][0] - 1].insert(wires[i][1] - 1);
            Links[wires[i][1] - 1].insert(wires[i][0] - 1);
        }

        for (int i = 0; i < n; i++)
        {
            int Count = DFS(i);
            if (Count != 0) //������ ������ Count�� 0�� �ƴҰ� ����� �ִ� ���� ����
            {
                DFS_Result[exeption].emplace_back(Count); //��� ������������ ��� ����. ���� �ϳ��� �������� 1~2���������� ����
            }
        }

        for (auto i : IsVisit) //DFS�ٳ����� ���� DFS�� ���� IsVisit �ʱ�ȭ
        {
            i = false;
        }

        int first = *(DFS_Result[exeption].begin()); //ù��° ������
        int second = 0;
        if (++DFS_Result[exeption].begin() != DFS_Result[exeption].end()) //������ 1���� ��� ����ó��
        {
            second = *(++DFS_Result[exeption].begin());
        }

        int CurDiffer = abs(first - second);

        if (CurDiffer == 0) //0�� ��� ��쿡�� �ּ�
        {
            return CurDiffer;
        }

        if (MinDiffer > CurDiffer)
        {
            MinDiffer = CurDiffer;
        }

        for (size_t i = 0; i < Links.size(); i++)
        {
            Links[i].clear(); //�ٿ��� �ʱ�ȭ
        }
        
        exeption++; //������ �� ���� �غ�
    }

    return MinDiffer; // �ּҰ� ����
}

int main()
{
    std::vector<std::vector<int>> EX = { {1, 3}, {2, 3}, {3, 4}, {4, 5}, {4, 6}, {4, 7}, {7, 8}, {7, 9} };
    int a = solution(EX.size() + 1, EX);
    return 0;
}