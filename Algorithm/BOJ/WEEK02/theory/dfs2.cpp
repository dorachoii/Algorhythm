#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[101][101];

vector<int> adj[10001];
int visited[10001];

void dfs(int u){
    visited[u] = 1;

    for(int v : adj[u]){
        if(visited[v]==0){
            dfs(V);
        }
    }
    return;
}


int main(){

    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j <m; j++){
            cin >> a[i][j];
        }
    }

    dfs(1);



}