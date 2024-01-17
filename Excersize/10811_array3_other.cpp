#include <iostream>
int a[101], m, n, i, j;

int main()
{
    std::cin >> n >> m;

    for (int b = 1; b <= n; b++)
        a[b] = b;

    for (; std::cin >> i >> j;)
        for (int b = i, c = j; b < c; b++, c--)
        {
            int t = a[b];
            a[b] = a[c];
            a[c] = t;           //반대로 돌려가며 뒤집기 vs 한 곳 뒤집기 어떻게 같지?
        }
    for (int b = 1; b <= n; b++)
        std::cout << a[b] << ' ';
}