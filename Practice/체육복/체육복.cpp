#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//정렬이 필수
//문제를 잘읽자
//인덱스와 실제 개수를 헷갈리지 말자

enum class StudentState
{
    Normal,
    Lost,
    Reserve
};

class Student
{
public:
    StudentState State = StudentState::Normal;
};

int solution(int n, vector<int> lost, vector<int> reserve)
{
    std::vector<Student> Students = std::vector<Student>();
    Students.resize(n);

    int AbleStudent = n;

	std::sort(lost.begin(), lost.end(), [](int a, int b) { return a < b; });

    for (size_t i = 0; i < reserve.size(); i++)
    {
		int StudentIndex = reserve[i] - 1;
        Students[StudentIndex].State = StudentState::Reserve;
    }

    for (size_t i = 0; i < lost.size(); i++)
    {
		int StudentIndex = lost[i] - 1;
        if (Students[StudentIndex].State == StudentState::Normal)
        {
            Students[StudentIndex].State = StudentState::Lost;
			AbleStudent--;
		}
		else if ((Students[StudentIndex].State == StudentState::Reserve))
		{
			Students[StudentIndex].State = StudentState::Normal;
			lost[i] = -99;
        }
    }

	for (size_t i = 0; i < lost.size(); i++)
	{
		if (lost[i] == -99)
		{
			continue;
		}
		int StudentIndex = lost[i] - 1;
		int PrevIndex = StudentIndex - 1;
		int PostIndex = StudentIndex + 1;

		if (PrevIndex >= 0)
		{
			if (Students[PrevIndex].State == StudentState::Reserve)
			{
				Students[PrevIndex].State = StudentState::Normal;
				Students[StudentIndex].State = StudentState::Normal;
				AbleStudent++;
			}
			else if (PostIndex < Students.size())
			{
				if (Students[PostIndex].State == StudentState::Reserve)
				{
					Students[PostIndex].State = StudentState::Normal;
					Students[StudentIndex].State = StudentState::Normal;
					AbleStudent++;
				}
			}
		}
		else if (PostIndex < Students.size())
		{
			if (Students[PostIndex].State == StudentState::Reserve)
			{
				Students[PostIndex].State = StudentState::Normal;
				Students[StudentIndex].State = StudentState::Normal;
				AbleStudent++;
			}
		}
	}

    return AbleStudent;
}

int main()
{
    int a = solution(5, {4,2}, {3,5});
    return 0;
}



