#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, j;
    cin >> n >> m >> j;

    int prevN, nextN;
    prevN = j;

    int frontB = j;
    int rearB = j;

    int cnt = 0;

    for (int i = 0; i < j; i++)
    {
        cin >> nextN;

        // 오른쪽 이동
        if (rearB < nextN)
        {
            int distance = nextN - rearB;
            if (distance > m)
            {
                distance = m;
            }
            cnt += distance;
            rearB += distance;
            frontB += distance;
        }
        // 왼쪽 이동
        else if (frontB > nextN)
        {
            int distance = frontB - nextN;
            if (distance > m)
            {
                distance = m;
            }
            cnt += distance;
            frontB -= distance;
            rearB -= distance;
        }

        prevN = nextN;
    }

    cout << cnt << endl;

    return 0;
}
