#include <iostream>

//최대공약수
long long GCD(long long left, long long right)
{
    long long Mod = left % right;
    if (Mod == 0)
    {
        return right;
    }
    return GCD(right, Mod);
}

//최소공배수
long long LCM(long long left, long long right)
{
    return left * right / GCD(left, right);
}

int main()
{
	return 0;
}