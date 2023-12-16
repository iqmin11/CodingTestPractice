#include <string>
#include <vector>
#include <map>

using namespace std;

std::vector<std::vector<int>> Land;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int XSize = 0;
int YSize = 0;

int DFS0(std::pair<int, int> _Start)
{
    Land[_Start.second][_Start.first] = 0;
    int Count = 1;

    for (int i = 0; i < 4; i++)
    {
        int CheckX = _Start.first + dx[i];
        int CheckY = _Start.second + dy[i];
        if (CheckX < 0 || CheckY < 0 || CheckX >= XSize || CheckY >= YSize)
        {
            continue;
        }

        if (Land[CheckY][CheckX] == 0)
        {
            continue;
        }

        Count += DFS0(std::make_pair(CheckX, CheckY));
    }
    return Count;
}

int solution0(vector<vector<int>> land) // 정확성 만점, 효율성 빵점 답안지
{
    Land = land;
    YSize = Land.size();
    XSize = Land[0].size();

    int MaxResult = INT32_MIN;

    for (int x = 0; x < XSize; x++)
    {
        int Result = 0;
        for (int y = 0; y < YSize; y++)
        {
            if (Land[y][x] == 0)
            {
                continue;
            }

            Result += DFS0(std::make_pair(x, y));
        }
        MaxResult = std::max(MaxResult, Result);
        Land = land;
    }

    return MaxResult;
}

int DFS1(std::pair<int, int> _Start, std::vector<std::pair<int, int>>& _Path)
{
    Land[_Start.second][_Start.first] = 0;
    int Count = 1;
    _Path.emplace_back(_Start);

    for (int i = 0; i < 4; i++)
    {
        int CheckX = _Start.first + dx[i];
        int CheckY = _Start.second + dy[i];
        if (CheckX < 0 || CheckY < 0 || CheckX >= XSize || CheckY >= YSize)
        {
            continue;
        }

        if (Land[CheckY][CheckX] == 0)
        {
            continue;
        }

        Count += DFS1(std::make_pair(CheckX, CheckY), _Path);
    }
    return Count;
}

std::vector<int> OliScore; //점수
std::vector<std::vector<int*>> ScoreMap;

int solution1(vector<vector<int>> land)
{
    Land = land;
    YSize = Land.size();
    XSize = Land[0].size();
    ScoreMap.resize(YSize);
    for (size_t i = 0; i < YSize; i++)
    {
        ScoreMap[i].resize(XSize, nullptr);
    }

    int MaxResult = INT32_MIN;
    OliScore.reserve(YSize * XSize);

    for (size_t y = 0; y < YSize; y++)
    {
        for (size_t x = 0; x < XSize; x++)
        {
            if (Land[y][x] == 0)
            {
                continue;
            }
            std::vector<std::pair<int, int>> TempPath;
            OliScore.emplace_back(DFS1(std::make_pair(x, y), TempPath));

            for (size_t i = 0; i < TempPath.size(); i++)
            {
                ScoreMap[TempPath[i].second][TempPath[i].first] = &OliScore.back();
            }
        }
    }

    std::vector<int> InitOilScore = OliScore;

    for (size_t x = 0; x < XSize; x++)
    {
        int TryScore = 0;
        for (size_t y = 0; y < YSize; y++)
        {
            if (ScoreMap[y][x] == nullptr)
            {
                continue;
            }
            TryScore += *ScoreMap[y][x];
            *ScoreMap[y][x] = 0;
        }
        MaxResult = std::max(MaxResult, TryScore);
        OliScore = InitOilScore;
    }

    return MaxResult;
}

int main()
{
    vector<vector<int>> land = 
    { {1, 0, 1, 0, 1, 1},
        {1, 0, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 1},
        {1, 0, 0, 1, 0, 0},
        {1, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1} };

    solution1(land);

    return 0;
}