#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

// 발음 가능한 모든 string 조합을 만들고 unordered_map으로 만들고
// bbabling을 돌면서 검색

//4! + 3! + 2! + 1!의 경우의 수가 있고, 24 + 6 + 2 + 1 = 33개면 걍 만들어도 될 정도긴한데
//0부터 n-1의 숫자를 정렬하는 경우의 수를 모두 나타내는 배열을 반환하는 함수

std::vector<std::vector<int>> AllSortNum(int _n)
{
    std::vector<std::vector<int>> result;
    result.resize(_n);
    std::vector<std::vector<int>> Addresult;
    Addresult.reserve(100);
    if (_n > 0)
    {
        for (int i = 0; i < _n; i++)
        {
            result[i].push_back(i);
        }

        Addresult = AllSortNum(_n - 1);

        if (Addresult.size() > 0)
        {
            for (int i = 0; i < result.size(); i++)
            {
                for (int j = 0; j < Addresult[i].size(); j++)
                {
                    result[i].push_back(Addresult[i][j]);
                }
            }
        }
    }

    return result;
}

int main()
{
    std::vector<std::vector<int>> A = AllSortNum(2);
    int answer = 0;
    return answer;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
