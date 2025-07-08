#include <bits/stdc++.h>
using namespace std;

int n, k, cnt, mnMove = 987654321, mnCnt;

// 함수에 인덱스를 매길 수 있나?
int move(int idx, int s)
{
    if (idx == 1)
    {
        return s - 1;
    }
    else if (idx == 2)
    {
        return s + 1;
    }
    else if (idx == 3)
    {
        return 2 * s;
    }
    else
    {
        return s;
    }
}

int solve(int s, int e)
{
    // 종료 조건: 시작점과 도착점이 같은 경우
    if (s == e)
    {
        return 0; // 이동 횟수를 반환
    }

    // 재귀 호출을 통해 도착점에 도달할 때까지 이동
    for (int i = 1; i <= 3; i++)
    {
        int ns = move(i, s);
        if (abs(ns - e) <= e)
        {          // 이동 후 도착점과의 거리가 도착점보다 작거나 같은 경우에만 재귀 호출
            cnt++; // 이동 횟수 증가
            int result = solve(ns, e);
            mnMove = min(mnMove, result + 1); // 이동 횟수 갱신
        }
    }

    return mnMove; // 최소 이동 횟수 반환
}

int main()
{
    cin >> n >> k;

    cout << solve(n, k);
    return 0;
}
