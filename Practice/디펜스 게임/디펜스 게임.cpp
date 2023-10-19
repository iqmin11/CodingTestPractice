#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Player
{
public:
    Player(int _n, int _k)
        : Soldier(_n), InvincibleCount(_k) {}

    int Soldier = 0;
    int InvincibleCount = 0;
};

bool FindInt(const std::vector<int>& _vec, int _find)
{
    auto StartIter = _vec.begin();
    auto EndIter = _vec.end();

    for (; StartIter != EndIter; StartIter++)
    {
        if (*StartIter == _find)
        {
            return true;
        }
    }

    return false;
}

int solution(int n, int k, vector<int> enemy)
{
    Player Junho(n, k);
    int TopScore = 0;
    vector<int> TopKEnemy = enemy;
    std::sort(TopKEnemy.begin(), TopKEnemy.end(), [](int _left, int _right)
        {
            return _left > _right;
        });
    TopKEnemy.resize(k);

    for (int Stage = 0; Stage < enemy.size(); Stage++)
    {
        //막는경우
        //1 비교적 너무 큰숫자인 경우
        if (FindInt(TopKEnemy, enemy[Stage]))
        {
            Junho.InvincibleCount--;
            TopScore = Stage + 1;
            continue;
        }
        //2 죽기직전
        else if (Junho.Soldier < enemy[Stage])
        {
            if (Junho.InvincibleCount > 0)
            {
                Junho.InvincibleCount--;
                TopScore = Stage + 1;
                continue;
            }
            else
            {
                //게임 오버
                TopScore = Stage;
                break;
            }
        }
        else
        {
            Junho.Soldier -= enemy[Stage];
            TopScore = Stage + 1;
        }
    }

    return TopScore;
}

int main()
{
    int answer = solution(7, 3, { 4, 2, 4, 5, 3, 3, 1 });
    int a = 0;
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
