//https://www.acmicpc.net/problem/15550

#include <iostream>
using namespace std;
int main() {
    int a = 1;
    long long b = 1;
    double c = 1;
    if (a == b && b == c && c != a) 
    {
        cout << "true" << '\n';
    }
    else {
        cout << "false" << '\n';
    }
    return 0;
}