#include <iostream>
#include <vector>

int N;
std::vector<bool> Start, End;

void LightSwitch(std::vector<bool>& _Lights, int Index) //
{
	int PrevIndex = Index - 1;
	int PostIndex = Index + 1;

	if (PrevIndex < 0)
	{
		_Lights[Index] = !_Lights[Index];
		_Lights[PostIndex] = !_Lights[PostIndex];
		return;
	}

	if (PostIndex >= N)
	{
		_Lights[PrevIndex] = !_Lights[PrevIndex];
		_Lights[Index] = !_Lights[Index];
		return;
	}

	_Lights[PrevIndex] = !_Lights[PrevIndex];
	_Lights[Index] = !_Lights[Index];
	_Lights[PostIndex] = !_Lights[PostIndex];
	return;
}

int main()
{
	std::cin >> N;
	Start.resize(N);
	End.resize(N);

	std::string temp;
	std::cin >> temp;
	for (size_t i = 0; i < N; i++)
	{
		Start[i] = static_cast<bool>(temp[i] - '0');
	}

	std::cin >> temp;
	for (size_t i = 0; i < N; i++)
	{
		End[i] = static_cast<bool>(temp[i] - '0');
	}

	if (Start == End)
	{
		std::cout << 0;
		return 0;
	}

	std::vector<bool>& Start0 = Start;
	std::vector<bool> Start1 = Start;
	LightSwitch(Start1, 0);
	int Count0 = 0;
	int Count1 = 1;

	for (size_t i = 1; i < N; i++)
	{
		if (Start0[i - 1] != End[i - 1])
		{
			++Count0;
			LightSwitch(Start0, i);
		}

		if (Start1[i - 1] != End[i - 1])
		{
			++Count1;
			LightSwitch(Start1, i);
		}
	}

	bool Result0 = Start0 == End;
	bool Result1 = Start1 == End;

	if (Result0 && Result1)
	{
		int result = 0;
		Count0 < Count1 ? result = Count0 : result = Count1;
		std::cout << result;
	}
	else
	{
		if (Result0 == true)
		{
			std::cout << Count0;
		}
		else if (Result1 == true)
		{
			std::cout << Count1;
		}
		else
		{
			std::cout << -1;
		}
	}

	return 0;
}