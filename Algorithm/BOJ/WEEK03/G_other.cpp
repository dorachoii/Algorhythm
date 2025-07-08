#include <bits/stdc++.h>
using namespace std;

const int MAX = 200000;
int visited[MAX + 4];
long long cnt[MAX + 4];

int main()
{
    int n, m;
    cin >> n >> m;


    if (n == m)
    {
        puts("0");
        puts("1");
        return 0;
    }

    visited[n] = 1;
    cnt[n] = 1;

    queue<int> q;
    q.push(n);

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        cout << "현재 " << now <<'\n';

        for (int next : {now - 1, now + 1, now * 2})
        {
            if (0 <= next && next <= MAX)
            {
                if (!visited[next])
                {
                    cout << "다음은 " << next <<"이고, 방문한 적 없어서 방문배열에 이동 누적"<< '\n';

                    q.push(next);
                    visited[next] = visited[now] + 1;
                    cnt[next] += cnt[now];
                    cout  << next <<"까지 누적된 이동은 " <<visited[next] << '\n';
                    cout << next << "까지의 경로는 " << cnt[next] <<"가지" << '\n';
                }
                else if (visited[next] == visited[now] + 1)
                {
                    cout << "다음은 " << next << "이고, 그리로 이동한 적이 있어서 경로 경우의 수만 갱신" << '\n';
                    cnt[next] += cnt[now];
                    cout << next << "까지의 경로는 " << cnt[next] << "가지" << '\n';
                }
            }
        }
    }
    cout << visited[m] - 1 << '\n';
    cout << cnt[m] << '\n';
    return 0;
}