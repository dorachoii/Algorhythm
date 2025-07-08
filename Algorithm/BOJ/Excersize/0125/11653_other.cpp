#include <iostream>
using namespace std;

int n, p = 1;

int main()
{
    for (cin >> n; n / ++p;)
        for (; n % p < 1; n /= p)
            cout << p << "\n";
}