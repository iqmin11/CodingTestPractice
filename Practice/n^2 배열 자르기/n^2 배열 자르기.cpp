#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right)
{
    vector<int> answer;
    answer.reserve(right - left + 1);

    //(0,0 ~ n,n) (i,j)
    //1���� �迭 �ε��� = (j+i*(n-1))
    //(j+i*(n-1)) == 2; �̰� �����ϴ� i�� j�� ã��
    //i�� j�� ũ�� ���ؼ� �� ū�� ���ڷ� �ٲٸ� ��

    for (; left <= right; left++)
    {
        int i = left / n;
        int j = left % n;

        if (i < j)
        {
            answer.push_back(j + 1);
        }
        else
        {
            answer.push_back(i + 1);
        }
    }

    return answer;
}