#include <bits/stdc++.h>
using namespace std;

// 문제는 1차원

// DFS : 인접 행렬, 방문 배열
// 자식노드 A로 부터 시작된 재귀함수 모두 돌리고, B로 넘어가서 모두 돌리고의 형식

// BFS : 인접 행렬, 방문 배열, queue
// 자식 노드 queue에 push하고 선입선출해서 pop하는 형식, 즉 레이어 순으로 들어가고 탐색됌.

//input
int n,m,v,a,b;

//dfs,bfs
const int max_n = 100004;
vector<int> adj[max_n];
int visitedDFS[max_n];
int visitedBFS[max_n];

//dfs함수
void dfs(int u){
    visitedDFS[u] = 1;     //방문해라!
    cout << u << " ";

    for(int v : adj[u]){   //인접한 리스트를 탐색하며 방문하지 않았다면 방문해라!
        if(visitedDFS[v]==0){
            dfs(v);
        }
    }

    return;
}

//bfs 함수
void bfs(int here){
    queue<int> q;
    visitedBFS[here] = 1;
    
    q.push(here);

    while(q.size()){
        int here = q.front();
        
        q.pop();
        cout << here << " ";

        for(int there : adj[here]){
            if(visitedBFS[there]) continue;
            
            visitedBFS[there] = visitedBFS[here] +1;
            
            q.push(there);
        }
    }
}



int main(){
    cin >> n >> m >> v;

    for(int i = 0; i < m; i++){
        cin >> a >> b;

        //1. DFS,BFS를 위한 인접리스트
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 0; i <n;i++){
        sort(adj[i].begin(), adj[i].end());
    }

    dfs(v);
    cout << '\n';
    bfs(v);

}