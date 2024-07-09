#include <iostream>
#include <vector>

std::vector<std::vector<int>> Image = 
{ 
	{1,2,3},
	{4,5,6},
	{7,8,9}
};

void DebugRender()
{
	std::cout << "////////////////////////////" << std::endl;

	for (int i = 0; i < Image.size(); i++)
	{
		for (int j = 0; j < Image[i].size(); j++)
		{
			std::cout << Image[i][j];
		}
		std::cout << std::endl;
	}

	std::cout << "////////////////////////////" << std::endl;
}

void RotateRect(std::vector<std::vector<int>>& Img)
{
	std::vector<std::vector<int>> temp;
	temp.resize(Img.size());

	for (int y = 0; y < temp.size(); y++)
	{
		temp[y].resize(Img[y].size(), 0);
	}

	for (int y = 0; y < Img.size(); y++)
	{
		for (int x = 0; x < Img[y].size(); x++)
		{
			temp[x][temp.size() - 1 - y] = Img[y][x];
		}
	}

	Img = temp;
}

int main()
{
	RotateRect(Image);
	DebugRender();
    return 0;
}