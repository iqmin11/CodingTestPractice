#include <iostream>

int ScreenSize = 0;
int BasketSize = 0;
int BasketMinIndex = 0;
int BasketMaxIndex = 0;

int Move(int _Apple)
{
	int AppleIndex = _Apple - 1;
	int MoveLenth = 0;

	if (AppleIndex >= BasketMinIndex && AppleIndex <= BasketMaxIndex )
	{
		return 0;
	}
	else if(AppleIndex < BasketMinIndex)
	{
		MoveLenth = BasketMinIndex - AppleIndex;
		BasketMinIndex -= MoveLenth;
		BasketMaxIndex -= MoveLenth;

		return MoveLenth;
	}
	else if (AppleIndex > BasketMaxIndex)
	{
		MoveLenth = AppleIndex - BasketMaxIndex;
		BasketMinIndex += MoveLenth;
		BasketMaxIndex += MoveLenth;
		return MoveLenth;
	}
}

int main()
{
	std::cin >> ScreenSize;
	std::cin >> BasketSize;
	BasketMinIndex = 0;
	BasketMaxIndex = 0 + (BasketSize - 1);

	int Answer = 0;
	int AppleCount = 0;
	std::cin >> AppleCount;
	for (size_t i = 0; i < AppleCount; i++)
	{
		int Temp = 0;
		std::cin >> Temp;
		Answer += Move(Temp);
	}

	std::cout << Answer;

	return 0;
}