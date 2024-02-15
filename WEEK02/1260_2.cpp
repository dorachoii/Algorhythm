#include <bits/stdc++.h>
using namespace std;

// input
int n, m, v, a, b;

// dfs,bfs
const int max_n = 1001; // 정점에 대한 연결 나타낼 것이므로 정점의 개수 1000이 max

vector<int> adj[max_n]; // 인접 행렬
int visitedDFS[max_n];  
int visitedBFS[max_n];

// dfs함수
// u: from 시작점 
void dfs(int u)
{
    visitedDFS[u] = 1; // 방문해라!
    cout << u << " ";

    for (int v : adj[u])
    { // 인접한 리스트를 탐색하며 방문하지 않았다면 방문해라!


        if (visitedDFS[v] == 0)
        {
            dfs(v);
        }
    }

    return;
}

// bfs 함수
void bfs(int here)
{
    queue<int> q;
    visitedBFS[here] = 1;

    q.push(here);

    while (q.size())
    {
        int here = q.front();

        q.pop();
        cout << here << " ";

        for (int there : adj[here])
        {
            if (visitedBFS[there])
                continue;

            visitedBFS[there] = visitedBFS[here] + 1;

            q.push(there);
        }
    }
}

int main()
{
    cin >> n >> m >> v;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;

        // 1. DFS,BFS를 위한 인접리스트
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    //여기 반복 범위를 [0,n)으로 설정했었음
    //[1,n]으로 고쳤더니 정답
    for (int i = 1; i <= n; i++)
    {
        sort(adj[i].begin(), adj[i].end());
    }

    dfs(v);
    cout << '\n';
    bfs(v);
}