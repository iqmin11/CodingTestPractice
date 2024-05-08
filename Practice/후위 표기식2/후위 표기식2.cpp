//문제 주소 : https://www.acmicpc.net/problem/1935

#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include <stack>

std::vector<double> Nums;
std::map<char, std::function<double(double, double)>> OperatorTable;

double Add(double left, double right)
{
	return left + right;
}

double Sub(double left, double right)
{
	return left - right;
}

double Mul(double left, double right)
{
	return left * right;
}

double Div(double left, double right)
{
	return left / right;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;
	std::string Cmd;
	std::cin >> Cmd;
	Nums.reserve(N);

	for (int i = 0; i < N; i++)
	{
		int Num;
		std::cin >> Num;
		Nums.push_back(Num);
	}

	OperatorTable.insert(std::make_pair('+', Add));
	OperatorTable.insert(std::make_pair('-', Sub));
	OperatorTable.insert(std::make_pair('*', Mul));
	OperatorTable.insert(std::make_pair('/', Div));

	std::stack<double> St;
	for (int i = 0; i < Cmd.size(); i++)
	{
		if (Cmd[i] < 'A' || Cmd[i] > 'Z')
		{
			double right = St.top();
			St.pop();
			double left = St.top();
			St.pop();
			St.push(OperatorTable[Cmd[i]](left, right));
		}
		else
		{
			St.push(Nums[Cmd[i] - 'A']);
		}
	}

	std::cout << std::fixed;
	std::cout.precision(2);
	std::cout << St.top();

	return 0;
}