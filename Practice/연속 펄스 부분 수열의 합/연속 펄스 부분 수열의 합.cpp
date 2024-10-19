#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> sequence)
{
    std::vector<std::vector<long long>> Version(2);
    Version[0].resize(sequence.size());
    for (int i = 0; i < sequence.size(); i++)
    {
        Version[0][i] = static_cast<long long>(sequence[i]);
    }

    Version[1] = Version[0];

    for (int i = 0; i < 2; i++)
    {
        long long NextMul;
        if (i == 0)
        {
            NextMul = -1;
        }
        else
        {
            NextMul = 1;
        }

        for (int j = 0; j < Version[i].size(); j++)
        {
            NextMul *= -1;
            Version[i][j] *= NextMul;
        }
    }

    //´©ÀûÇÕ PrefixSum
    for (int i = 0; i < 2; i++)
    {
        for (int j = 1; j < Version[i].size(); j++)
        {
            Version[i][j] += Version[i][j - 1];
        }
    }

    if (Version[0].size() == 1 && Version[1].size() == 1)
    {
        return std::max(Version[0][0], Version[1][0]);
    }

    std::vector<long long> VersionMax(2, INT64_MIN);

    for (int i = 0; i < 2; i++)
    {
        long long PrefixMin = 0;
        for (int j = 1; j < Version[i].size(); j++)
        {
            PrefixMin = std::min(Version[i][j - 1], PrefixMin);
            VersionMax[i] = std::max(Version[i][j] - PrefixMin, VersionMax[i]);
        }
    }


    long long answer = std::max(VersionMax[0], VersionMax[1]);
    return answer;
}

int main()
{
    solution({ -5 });

    return 0;
}