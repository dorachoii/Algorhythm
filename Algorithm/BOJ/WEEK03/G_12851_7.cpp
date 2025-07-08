#include <bits/stdc++.h>
using namespace std;

int n, k, cnt, mnMove = 987654321, mnCnt;

// 함수에 인덱스를 매길 수 있나?
int move(int idx, int s, int e)
{
    if (idx == 1)
    {
        if(s < e){
            return s + 1;
        }else {
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
    cout << "현재 위치는 " << s <<'\n';

    if (s == e)
    {
        if (mnMove == cnt)
            mnCnt++;
        mnMove = min(cnt, mnMove);
        cnt = 0;
        return mnMove;
    }


    for (int i = 1; i <3; i++)
    {
        cout << "현재 " << i << "번째 함수 실행 중\n";

        int ns = move(i, s, e);
        cout <<"다음 위치는 " << ns <<'\n';

        if (ns - e > e){
            cout << ns <<"가 e보다 너무 커서 패스\n";
            continue;
        }

        cnt++;
        
        int ret = solve(ns, e);
        mnMove = min(ret, mnMove);
    }

    return cnt;
}

int main()
{
    cin >> n >> k;

    cout << solve(n, k) <<'\n';
    cout << mnCnt;
}