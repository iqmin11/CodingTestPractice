#include <string>
#include <vector>

using namespace std;

std::vector<std::vector<int>> DPtri;

int solution(vector<vector<int>> triangle)
{
    DPtri.resize(triangle.size());
    for (int i = 0; i < DPtri.size(); i++)
    {
        DPtri[i].resize(i + 1);
    }

    DPtri[0][0] = triangle[0][0];

    for (int i = 1; i < DPtri.size(); i++)
    {
        for (int j = 0; j < DPtri[i].size(); j++)
        {
            if (j == 0)
            {
                DPtri[i][j] = DPtri[i - 1][j] + triangle[i][j];
            }
            else if (j == DPtri[i].size() - 1)
            {
                DPtri[i][j] = DPtri[i - 1][j - 1] + triangle[i][j];
            }
            else
            {
                DPtri[i][j] = std::max(DPtri[i - 1][j - 1] + triangle[i][j],
                    DPtri[i - 1][j] + triangle[i][j]);
            }
        }
    }

    int Max = INT32_MIN;
    for (int i = 0; i < DPtri[DPtri.size() - 1].size(); i++)
    {
        if (Max < DPtri[DPtri.size() - 1][i])
        {
            Max = DPtri[DPtri.size() - 1][i];
        }
    }

    return Max;
}