#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int j;
    cin >> j;

    int prevv, nextt;
    cin >> prevv;

    int cnt = 0;
    for (int i = 1; i < j; i++)
    {
        cin >> nextt;

        int distance = abs(nextt - prevv) - 1; // 현재 위치와 이전 위치 사이의 바구니 이동 횟수
        cnt += max(0, distance - 1);           // 범위를 넘어가는 이동은 제외

        prevv = nextt; // 다음 루프를 위해 이전 위치 갱신
    }

    cout << cnt << endl;

    return 0;
}
