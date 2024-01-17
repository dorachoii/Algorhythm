#include <iostream>
int a[101], m, n, i, j;

// 근데 m은 안쓰는 방법인가?
int main()
{
    std::cin >> n >> m;

    for (int b = 1; b <= n; b++)    // 미리 배열 만들어두고 쓰는 거니까, 인덱스도 0으로 바꿀 필요가 없구나.
        a[b] = b;

    for (; std::cin >> i >> j;)
    {
        int t = a[i];
        a[i] = a[j];
        a[j] = t; // 여기서도 t하나로만 바꿀 수 있는 로직
    }
    for (int b = 1; b <= n; b++)
        std::cout << a[b] << ' ';
}