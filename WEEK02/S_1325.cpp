#include <bits/stdc++.h>
using namespace std;

// 보통 문제가 아니군

int n, m, u, v;

vector<int> adj[10004];
visited[10004];

vector<int> computerN;

int fs(int n)
{
    visited[n] = true;
    for (int i = 0; i < adj[n].size(); i++)
    {
        if (visited[adj[n][i]]) continue;
        fs(adj[n][i]);
        cnt++;
    }
    return cnt;
}

int main()
{

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> v >> u;

        adj[u].push_back(v);
    }

    for(int i = 0; i < n; i++){
        if(!visited[n]) 
        {
            int k = fs(n);
            
            if(k )

        }
    }
}