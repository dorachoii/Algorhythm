#include <bits/stdc++.h>
using namespace std;

vector<int> G[1001];
int visited[1001];

void dfs(int cur){
    visited[cur] = true;

     for(int nxt: G[cur]){
        if(!visited[nxt]){
            dfs(nxt);
        }
    }
}   

void bfs(int cur){
    
}


int main(){
    int N,M; cin>> N>> M;

    for(int i = 0; i < M; ++i){
        int u,v; cin>> u >> v;
        
        // 인접행렬, 양방향
        G[u].push_back(v);
        G[v].push_back(u);
        
    }

    int res =0;

    for(int i = 1; i <=N; ++i){
        if(!visited[i]){
            res++;
            dfs(i);
        }
    }

    cout << res;
}  