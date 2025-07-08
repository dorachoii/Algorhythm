#include <iostream>
#include <climits>
using namespace std;

int n, k, cnt, mnMove = INT_MAX, mnCnt = 0;

int move(int idx, int s, int e)
{
    if (idx == 1)
    {
        if (s < e)
        {
            return s + 1;
        }
        else
        {
            return s - 1;
        }
    }
    else if (idx == 2)
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
    //cout << "현재 위치는 " << s << '\n';

    if (s == e)
    {
        if(mnMove == cnt)
            mnCnt++;
        mnMove = min(cnt, mnMove); // 도착점에 도착했을 때 이동 횟수를 갱신
                          // 도착점에 도착한 경우 카운트
        return mnMove-1;             // 이동 횟수 반환
    }

    int minMove = INT_MAX; // 현재 위치에서의 최소 이동 횟수를 저장하기 위한 변수

    for (int i = 1; i <= 2; i++)
    {
        //cout << "현재 " << i << "번째 함수 실행 중\n";

        int ns = move(i, s, e);
        //cout << "다음 위치는 " << ns << '\n';

        if (ns - e > e)
        {
            //cout << ns << "가 e보다 너무 커서 패스\n";
            continue;
        }

        cnt++;                       // 이동 횟수 증가
        int ret = solve(ns, e);      // 재귀 호출
        minMove = min(ret, minMove); // 현재 위치에서의 최소 이동 횟수 갱신
        cnt--;                       // 이동 횟수 감소
    }

    return minMove; // 최소 이동 횟수 반환
}

int main()
{
    cin >> n >> k;

    cout << solve(n, k) << '\n';
    cout << mnCnt;
}
