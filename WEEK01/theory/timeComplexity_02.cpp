#include <bits/stdc++.h>
using namespace std;

int N, M, cnt;

void solve(int N, int M)
{
    int a = 1;

    for (int i = 0; i < N; i++)
    {
        a *= i;
        cnt++;
    }
    for (int j = 0; i < M; j++)
    {
        a *= j;
        cnt++;
    }

    cout << a << "\n";
}

int main()
{

    cin >> N >> M;

    solve(N, M);
}