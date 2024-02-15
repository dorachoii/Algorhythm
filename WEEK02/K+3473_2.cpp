#include <bits/stdc++.h>
using namespace std;

// 시간 초과
// 구간합?
int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;

        int five = 0;

        // 5의 개수 계산
        for (int j = 5; j <= k; j += 5)
        {
            int num = j;
            while (num % 5 == 0)
            {
                five++;
                num /= 5;
            }
        }

        cout << five << '\n';
    }

    return 0;
}
