#include <bits/stdc++.h>
using namespace std;

int N, K;

int main()
{

    cin >> N >> K;

    int a[N];int sum[N-K+1];

    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < N - K + 1; i++)
    {
        int s = 0;
        for (int j = i; j < i + K; j++)
        {
            s += a[j];
            sum[i] = s;
        }
    }

    sort(sum,sum+N-K+1);

    cout << sum[N-K];
}
//이건 또 시간초과 남..