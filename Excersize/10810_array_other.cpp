#include <iostream>

//1차원으로 풀 수 있음..

int a[101], m, n, i, j, k;                              // N보다 1크게 설정해서 미리 만들었네.

int main()
{
    for (std::cin >> n >> m; std::cin >> i >> j >> k;)  // n,m 입력받고 i j k 는 있을 때까지 계속 반복해서 받는다.
        for (int b = i; b <= j; b++)
            a[b] = k;

    for (int b = 1; b <= n; b++)
        std::cout << a[b] << ' ';                       // /n 없어도 끝나는 군

    
}