#include <vector>
#include <set>

using namespace std;
std::vector<std::set<int>> LinkNodes;
std::vector<bool> IsVisit;

int DFS(int _Start)
{
    IsVisit[_Start] = true;
    int Count = 1;

    for (auto& LinkNode : LinkNodes[_Start])
    {
        if (!IsVisit[LinkNode])
        {
            Count += DFS(LinkNode);
        }
    }
    return Count;
}

int solution(int n, vector<vector<int>> wires)
{
    int m = n - 1; //���� ����
    LinkNodes.resize(n);
    IsVisit.resize(n);

    int MinDiffer = INT32_MAX;

    for (int Cut = 0; Cut < m; Cut++) //������ �ѹ��� �߶� ���ڴ�
    {
        int CutFirstValue = wires[Cut][0]; // ���� �ڸ��� ������ �ϳ� ����
        for (int i = 0; i < m; i++)
        {
            if (Cut == i) // �� �ڸ���
            {
                continue;
            }
            LinkNodes[wires[i][0] - 1].insert(wires[i][1] - 1);
            LinkNodes[wires[i][1] - 1].insert(wires[i][0] - 1);
        }

        int Left = DFS(CutFirstValue);
        int Right = abs(n - Left);

        MinDiffer = std::min(abs(Left - Right), MinDiffer);
        if (MinDiffer == 0)
        {
            return MinDiffer;
        }

        for (int i = 0; i < n; i++) //�ʱ�ȭ
        {
            IsVisit[i] = false;
            LinkNodes[i].clear();
        }
    }

    return MinDiffer;
}

int main()
{
    std::vector<std::vector<int>> EX = { {1, 3}, {2, 3}, {3, 4}, {4, 5}, {4, 6}, {4, 7}, {7, 8}, {7, 9} };
    int a = solution(EX.size() + 1, EX);
    return 0;
}