#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right)
{
    vector<int> answer;
    answer.reserve(right - left + 1);

    //(0,0 ~ n,n) (i,j)
    //1차원 배열 인덱스 = (j+i*(n-1))
    //(j+i*(n-1)) == 2; 이걸 만족하는 i와 j를 찾고
    //i랑 j를 크기 비교해서 더 큰쪽 숫자로 바꾸면 됨

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