#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    int A[N];
    for (int i = 0; i < N; i++)
        cin >> A[i];

    // 윈도우(구간)의 크기는 K
    int answer, result = 0;
    for (int i = 0; i < K; i++)
        result += A[i]; // [0, K - 1] 구간
        
    answer = result;

    for (int i = K; i < N; i++)
    { // [i - K + 1, i] 구간
        result += A[i];
        result -= A[i - K];
        answer = max(answer, result);
    }

    cout << answer;
}