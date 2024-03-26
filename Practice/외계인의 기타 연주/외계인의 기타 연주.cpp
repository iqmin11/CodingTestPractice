#include <iostream>
#include <vector>
#include <stack>
#include <queue>

int main()
{
	int N, P;

	std::cin >> N >> P;

	std::vector<std::stack<int>> Guitar;
	std::queue<std::pair<int, int>> Note;

	for (size_t i = 0; i < N; i++)
	{
		std::pair<int, int> InsertNote;
		std::cin >> InsertNote.first >> InsertNote.second;
		Note.push(InsertNote);
	}

	Guitar.resize(6);
	int MoveCount = 0;

	while (!Note.empty())
	{
		int Line, Melody;
		Line = Note.front().first - 1;
		Melody = Note.front().second;
		
		if (Guitar[Line].empty())
		{
			Guitar[Line].push(Melody); //손가락을 누름
			MoveCount++;
			Note.pop(); //연주
			continue;
		}

		while (!Guitar[Line].empty())
		{
			int CheckHighstMelody = Guitar[Line].top();
			if (Melody > CheckHighstMelody)
			{
				Guitar[Line].push(Melody); //손가락을 누름
				MoveCount++;
				Note.pop(); //연주
				break;
			}
			else if (Melody == CheckHighstMelody)
			{
				Note.pop(); //연주
				break;
			}

			while (Melody < CheckHighstMelody)
			{
				Guitar[Line].pop(); //손가락을 뗌
				MoveCount++;

				if (!Guitar[Line].empty())
				{
					CheckHighstMelody = Guitar[Line].top();
				}
				else
				{
					CheckHighstMelody = 0;
				}
			}
		}
	}

	std::cout << MoveCount;
}