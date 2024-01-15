#include <string>
#include <vector>
#include <algorithm>

using namespace std;

std::vector<std::string> Division(std::string _FileName)
{
	std::vector<std::string> result;
	result.reserve(3);
	int Check = 0;
	for (int i = 0; i < _FileName.size(); ++i)
	{
		if (result.empty())
		{
			if (_FileName[i] >= '0' && _FileName[i] <= '9')
			{
				Check = i;
				result.push_back(_FileName.substr(0, Check));
			}
		}
		else if (!(_FileName[i] >= '0' && _FileName[i] <= '9'))
		{
			result.push_back(_FileName.substr(Check, i - Check));
			result.push_back(_FileName.substr(i, _FileName.size() - 1));
			break;
		}

	}

	if (result.size() != 3)
	{
		result.push_back(_FileName.substr(Check, result.size() - Check));
		result.push_back("\0");
	}

	for (size_t i = 0; i < result[0].size(); i++)
	{
		result[0][i] = toupper(result[0][i]);
	}

	return result;
}

vector<string> solution(vector<string> files)
{
    std::stable_sort(files.begin(), files.end(), [](std::string _Left, std::string _Right)
        {
            std::vector<std::string> LeftResult = Division(_Left);
            std::vector<std::string> RightResult = Division(_Right);

            if (LeftResult[0] != RightResult[0])
            {
                return LeftResult[0] < RightResult[0];
            }

            int LeftNumber = std::stoi(LeftResult[1]);
            int RightNumber = std::stoi(RightResult[1]);

            if (LeftNumber != RightNumber)
            {
                return LeftNumber < RightNumber;
            }
            return false;
        });

    return files;
}

int main()
{
    solution({ "img01", "img1" });

}
