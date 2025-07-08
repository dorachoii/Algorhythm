#include <bits/stdc++.h>
using namespace std;

int n, k, a, b, Dcnt, Ocnt;

int oneMove(int a, int b)
{
    cout << "오른쪽 1칸 이동" << '\n';

    while (a != b)  // 이렇게 while을 쓰면 왜 무한반복인지 써보기
    {
        Ocnt++;
        oneMove(a + 1, b);
    }

    return Ocnt;
}

int main()
{

    cin >> n >> k;

    n >= k ? (a = k, b = n) : (a = n, b = k);

    cout << oneMove(a, b);
}
