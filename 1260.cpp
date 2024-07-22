#include <bits/stdc++.h>
using namespace std;

// 방문 배열
int visited[10004];
// 인접 리스트
vector<int> G[1001];

void dfs(int cur) {
    visited[cur] = 1;
    cout << cur << " "; 

    for (auto nxt : G[cur]) {
        if (!visited[nxt]) {
            dfs(nxt);
        }
    }
}

void bfs(int cur) {
    queue<int> q;
    q.push(cur);

    cout << cur << " ";

    visited[cur] = 1;

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (auto nxt : G[cur]) {
            if (!visited[nxt]) {
                q.push(nxt);
                visited[nxt] = 1;
                cout << nxt << " ";
            }
        }
    }
}

//초기화
void init() {
    memset(visited, 0, sizeof(visited));
}

int main() {
    int N, M, V;
    cin >> N >> M >> V;

    for (int i = 0; i < M; ++i) {
        int u, v; cin >> u >> v;

        G[u].push_back(v);
        G[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        sort(G[i].begin(), G[i].end());
    }

    dfs(V);
    cout << '\n';

    // 초기화
    init();

    bfs(V);
}


// 컴퓨터가 사칙연산할때! : 전위, 후위 , 중위 순회 생김
// 섬의 개수 

// 요즘 union find tree! 