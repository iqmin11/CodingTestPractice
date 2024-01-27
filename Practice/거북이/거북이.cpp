#include <iostream>
#include <vector>

//µ¿¼­³²ºÏ = 0 1 2 3
int Top = 0;
int Bot = 0;
int Left = 0;
int Right = 0;

class Turtle
{
public:
	
	void Move(const std::string& _Command)
	{
		for (size_t i = 0; i < _Command.size(); i++)
		{
			switch (_Command[i])
			{
			case 'F':
				LocationX += dx[Dir];
				LocationY += dy[Dir];

				Top = std::max(Top, LocationY);
				Bot = std::min(Bot, LocationY);
				Left = std::min(Left, LocationX);
				Right = std::max(Right, LocationX);
				break;
			case 'B':
				if (Dir >= 2)
				{
					LocationX += dx[Dir - 2];
					LocationY += dy[Dir - 2];
				}
				else
				{
					LocationX += dx[Dir + 2];
					LocationY += dy[Dir + 2];
				}

				Top = std::max(Top, LocationY);
				Bot = std::min(Bot, LocationY);
				Left = std::min(Left, LocationX);
				Right = std::max(Right, LocationX);
				break;
			case 'L':
			{
				int NextDir = Dir - 1;
				if (NextDir < 0)
				{
					NextDir = 3;
				}
				Dir = NextDir;
			}
			break;
			case 'R':
			{
				int NextDir = Dir + 1;
				if (NextDir > 3)
				{
					NextDir = 0;
				}
				Dir = NextDir;
			}
			break;
			default:
				break;
			}
		}
	}

	int LocationX = 0; //x
	int LocationY = 0; //x
	int Dir = 1; // 0 1 2 3
	//µ¿ ºÏ ¼­ ³²
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
};

int main()
{

	int N;
	std::cin >> N;
	std::vector<std::string> Commands;
	std::vector<int> Answers;
	Commands.resize(N);
	Answers.reserve(N);
	for (size_t i = 0; i < N; i++)
	{
		Right = 0;
		Left = 0;
		Top = 0;
		Bot = 0;
		std::cin >> Commands[i];

		Turtle Paly;
		Paly.Move(Commands[i]);

		int Answer = (Right - Left) * (Top - Bot);
		Answers.push_back(Answer);
	}

	for (size_t i = 0; i < N; i++)
	{
		std::cout << Answers[i] << '\n';
	}
}