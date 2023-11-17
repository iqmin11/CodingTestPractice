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

    while (exeption < n) // 전선을 다 끊어볼때까지 돌거야
    {
        for (int i = 0; i < wires.size(); i++)
        {
            //전선 끊기
            if (i == exeption)
            {
                continue;
            }
            //전선 끊은 채로 길연결
            Links[wires[i][0] - 1].insert(wires[i][1] - 1);
            Links[wires[i][1] - 1].insert(wires[i][0] - 1);
        }

        for (int i = 0; i < n; i++)
        {
            int Count = DFS(i);
            if (Count != 0) //영역이 있으면 Count가 0은 아닐것 결과가 있는 값만 저장
            {
                DFS_Result[exeption].emplace_back(Count); //모든 시작점에서의 결과 저장. 길을 하나만 끊었으니 1~2개영역으로 나뉨
            }
        }

        for (auto i : IsVisit) //DFS다끝나면 다음 DFS를 위해 IsVisit 초기화
        {
            i = false;
        }

        int first = *(DFS_Result[exeption].begin()); //첫번째 영역값
        int second = 0;
        if (++DFS_Result[exeption].begin() != DFS_Result[exeption].end()) //영역이 1개인 경우 예외처리
        {
            second = *(++DFS_Result[exeption].begin());
        }

        int CurDiffer = abs(first - second);

        if (CurDiffer == 0) //0이 모든 경우에서 최선
        {
            return CurDiffer;
        }

        if (MinDiffer > CurDiffer)
        {
            MinDiffer = CurDiffer;
        }

        for (size_t i = 0; i < Links.size(); i++)
        {
            Links[i].clear(); //줄연결 초기화
        }
        
        exeption++; //다음번 줄 끊기 준비
    }

    return MinDiffer; // 최소값 리턴
}

int main()
{
    std::vector<std::vector<int>> EX = { {1, 3}, {2, 3}, {3, 4}, {4, 5}, {4, 6}, {4, 7}, {7, 8}, {7, 9} };
    int a = solution(EX.size() + 1, EX);
    return 0;
}