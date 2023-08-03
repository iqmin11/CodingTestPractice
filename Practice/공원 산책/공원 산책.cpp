#include <iostream>
#include <string>
#include <vector>

using namespace std;

class int2
{
public:
    int2()
    {
    }

    int2(int _x, int _y)
        : x(_x), y(_y)
    {
    }

    bool operator==(const int2& _Value)
    {
        return _Value.x == x && _Value.y == y;
    }

    int x = 0;
    int y = 0;
};

vector<int> solution(vector<string> park, vector<string> routes)
{
    //공원의 구조를 파악하기
    int2 ParkMaxIndex = int2(park[0].length() - 1, park.size() - 1);
    std::vector<int2> Collision;
    int2 StartPosition;
    Collision.reserve(2500);
    for (int y = 0; y < park.size(); y++)
    {
        for (int x = 0; x < park[y].length(); x++)
        {
            if (park[y][x] == 'S')
            {
                StartPosition = int2(x, y);
            }
            else if (park[y][x] == 'X')
            {
                Collision.emplace_back(int2(x, y));
            }
        }
    }

    //강아지 만들기
    int2 Dog = StartPosition;

    //강아지를 움직이는 함수 만들기
    for (int i = 0; i < routes.size(); i++)
    {
        char Dir = routes[i][0];
        //int Distance = static_cast<int>(routes[i][2]) - '0'; //이런건 작은 꿀팁이지만 사실 이런것보다 std함수를 쓸수 있다면 그게 더 안전할 것.
        int Distance = std::atoi(&routes[i][2]); //std::atoi() c스타일의 문자열을 int로 cf) string을 바꾸는 std::stoi()도 있음
        int2 NextPos = Dog;

        switch (Dir) //강아지의 예상 위치 저장
        {
        case 'N':
            NextPos.y -= Distance;
            break;
        case 'S':
            NextPos.y += Distance;
            break;
        case 'E':
            NextPos.x += Distance;
            break;
        case 'W':
            NextPos.x -= Distance;
            break;
        }

        // 이동 가능 여부에 따른 예외처리
        bool CanDogGo = true;
        int2 ScanPos = Dog;
        if (NextPos.y > ParkMaxIndex.y ||
            NextPos.x > ParkMaxIndex.x ||
            NextPos.y < 0 ||
            NextPos.x < 0)
        {
            CanDogGo = false;
        }
        else if (Dir == 'N')
        {
            for (int y = 0; y < Distance; y++)
            {
                --ScanPos.y;
                for (int i = 0; i < Collision.size(); i++)
                {
                    if (ScanPos == Collision[i])
                    {
                        CanDogGo = false;
                        break;
                    }
                }

                if (CanDogGo == false)
                {
                    break;
                }
            }
        }
        else if (Dir == 'S')
        {
            for (int y = 0; y < Distance; y++)
            {
                ++ScanPos.y;
                for (int i = 0; i < Collision.size(); i++)
                {
                    if (ScanPos == Collision[i])
                    {
                        CanDogGo = false;
                        break;
                    }
                }

                if (CanDogGo == false)
                {
                    break;
                }
            }
        }
        else if (Dir == 'W')
        {
            for (int x = 0; x < Distance; x++)
            {
                --ScanPos.x;
                for (int i = 0; i < Collision.size(); i++)
                {
                    if (ScanPos == Collision[i])
                    {
                        CanDogGo = false;
                        break;
                    }
                }

                if (CanDogGo == false)
                {
                    break;
                }
            }
        }
        else
        {
            for (int x = 0; x < Distance; x++)
            {
                ++ScanPos.x;
                for (int i = 0; i < Collision.size(); i++)
                {
                    if (ScanPos == Collision[i])
                    {
                        CanDogGo = false;
                        break;
                    }
                }

                if (CanDogGo == false)
                {
                    break;
                }
            }
        }

        if (CanDogGo) //갈수 있는 조건이면
        {
            Dog = NextPos; //이동한다
        }
    }

    vector<int> answer;
    answer.emplace_back(Dog.y);
    answer.emplace_back(Dog.x);
    return answer;
}

int main()
{
    vector<string> park({ "OSO", "OOO", "OXO", "OOO" });
    vector<string> routes({ "E 2", "S 3", "W 1" });
    std::vector<int> result = solution(park, routes);
    for (size_t i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << std::endl;
    }
}

// 코딩테스트는 컴파일러도없는데
// 실수하면 어떻게 고쳐야되냐가 고민이네... 그게 크게 중요한가?
// 실수를 안하는것 보다 실수를 고칠 수 있는 능력이 더 중요하다고 생각되는데.

