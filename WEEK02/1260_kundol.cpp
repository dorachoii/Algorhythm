#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> a[1001];
bool check[1001];   //방문행렬도 하나로 쓰고 초기화

void dfs(int node)
{
    check[node] = true;
    cout << node << ' ';
    for (int i = 0; i < a[node].size(); i++)
    {
        int next = a[node][i];
        if (!check[next])
        {
            dfs(next);
        }
    }
}

void bfs(int start)
{
    queue<int> q;
    memset(check, false, sizeof(check));
    q.push(start);
    check[start] = true;

    while (q.size())
    {
        int node = q.front();
        q.pop();
        cout << node << ' ';
        ;
        for (int i = 0; i < a[node].size(); i++)
        {
            int next = a[node][i];
            if (!check[next])
            {
                check[next] = true;
                q.push(next);
            }
        }
    }
}

int main()
{
    int n, m, start;
    scanf("%d %d %d", &n, &m, &start);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
        sort(a[i].begin(), a[i].end());

    dfs(start);
    printf("\n");
    bfs(start);
    printf("\n");
    return 0;
}