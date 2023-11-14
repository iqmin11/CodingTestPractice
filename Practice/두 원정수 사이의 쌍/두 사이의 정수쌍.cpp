#include <string>
#include <vector>

using namespace std;

long long solution(int r1, int r2)
{
    long long result = 0;
    long long r1r1 = static_cast<long long>(pow(r1, 2));
    long long r2r2 = static_cast<long long>(pow(r2, 2));
    for (int x = 1; x <= r2; x++)
    {
        long long xx = static_cast<long long>(pow(x, 2));
        long long yMax = static_cast<long long>(sqrt(static_cast<double>(r2r2 - xx)));
        long long yMin = 0;
        if (x < r1)
        {
            yMin = static_cast<long long>(ceil(sqrt(static_cast<double>(r1r1 - xx))));
        }
        result += yMax - yMin + 1;
    }

    long long answer = result * 4;
    return answer;
}

int main()
{
    long long a = solution(2, 3);

    return 0;
}