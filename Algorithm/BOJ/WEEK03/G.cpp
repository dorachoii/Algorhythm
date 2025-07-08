#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n, k,cnt;

int solve(int n, int k)
{
    vector<int> dp(2 * k + 1, INT_MAX); // 동적 계획법을 위한 배열, dp[i]는 위치 i까지 가는 최소 이동 횟수를 저장
    dp[n] = 0;                          // 시작 위치의 최소 이동 횟수는 0

    for (int i = n; i <= k; ++i)
    {
        if (dp[i] == INT_MAX)
            continue; // 현재 위치에 도달할 수 없는 경우, 다음 위치로 넘어감
        if (i * 2 <= 2 * k)
            int k = dp[i *2];
            dp[i * 2] = min(dp[i * 2], dp[i] + 1); // 순간이동하는 경우

            if(k == dp[i*2]) cnt++;
        if (i + 1 <= k)
            int k = dp[i + 1];
            dp[i + 1] = min(dp[i + 1], dp[i] + 1); // 한 칸 앞으로 이동하는 경우
            if(k == dp[i*2]) cnt++;
        if (i - 1 >= 0)
            int k = dp[i-1];
            dp[i - 1] = min(dp[i - 1], dp[i] + 1); // 한 칸 뒤로 이동하는 경우
    }

    return dp[k];
}

int main()
{
    cin >> n >> k;
    cout << solve(n, k) << endl;
    return 0;
}
