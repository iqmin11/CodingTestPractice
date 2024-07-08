#include <iostream>
#include <vector>
#include <deque>

int main()
{
	int WindowSize = 3;
	int Right = 0;

	std::vector<int> Arr = {1,1,2,2,8,8,3,5,5,0,0};

	std::deque<int> Window;

	if (Arr[0] != Arr[1])
	{
		std::cout << Window[0] << std::endl;
		return 0;
	}

	if (Arr.back() != *std::prev(std::prev(Arr.end())))
	{
		std::cout << Arr.back() << std::endl;
		return 0;
	}

	for (int Left = 0; Left < Arr.size() - WindowSize; Left++)
	{
		while (Window.size() < WindowSize && Right < Arr.size())
		{
			Window.push_back(Arr[Right]);
			Right++;
		}

		if (Window[0] != Window[1] && Window[1] != Window[2])
		{
			std::cout << Window[1] << std::endl;
			break;
		}

		Window.pop_front();
	}

    return 0;
}