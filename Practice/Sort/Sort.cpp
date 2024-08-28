#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> Target = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };

void Print()
{
	for (size_t i = 0; i < Target.size(); i++)
	{
		std::cout << Target[i] << " ";
	}
	std::cout << std::endl;
}

void Shuffle()
{
	std::random_shuffle(Target.begin(), Target.end());
	Print();
}

//Sorting Algorithm
void SelectionSort(std::vector<int>& Arr)
{
	for (int i = 0; i < Arr.size(); i++)
	{
		int MinValue = INT32_MAX;
		int MinIndex = -1;

		for (int j = i; j < Arr.size(); j++)
		{
			if (MinValue > Arr[j])
			{
				MinValue = Arr[j];
				MinIndex = j;
			}
		}

		std::swap(Arr[i], Arr[MinIndex]);
	}
	Print();
}

void InsertionSort(std::vector<int>& Arr)
{
	for (int i = 1; i < Arr.size(); i++)
	{
		int Temp = Arr[i];
		int j;

		for (j = i - 1; j >= 0; --j)
		{
			if (Temp >= Arr[j])
			{
				break;
			}

			Arr[j + 1] = Arr[j];
		}

		Arr[j + 1] = Temp;
	}

	Print();
}

void BubbleSort(std::vector<int>& Arr)
{
	for (int i = 0; i < Arr.size() - 1; i++)
	{
		for (int j = 0; j < Arr.size() - i - 1; j++)
		{
			if (Arr[j] > Arr[j + 1])
			{
				std::swap(Arr[j], Arr[j + 1]);
			}
		}
	}

	Print();
}

void QuickSort(std::vector<int>& Arr, int Left, int Right)
{
	if (Left < Right)
	{
		int Pivot = Arr[Right];
		int PivotIndex = Left - 1;

		for (int j = Left; j < Right; j++)
		{
			if (Arr[j] <= Pivot)
			{
				PivotIndex++;
				std::swap(Arr[PivotIndex], Arr[j]);
			}
		}

		std::swap(Arr[++PivotIndex], Arr[Right]);

		QuickSort(Arr, Left, PivotIndex - 1);
		QuickSort(Arr, PivotIndex + 1, Right);
	}

	Print();
}

int main()
{
	//Shuffle();
	//SelectionSort(Target);

	//Shuffle();
	//InsertionSort(Target);

	//Shuffle();
	//BubbleSort(Target);

	Shuffle();
	Shuffle();
	Shuffle();
	QuickSort(Target, 0, Target.size() - 1);
}