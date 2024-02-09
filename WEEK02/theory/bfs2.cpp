#include <bits/stdc++.h>
using namespace std;

int n, m, sx,sy,ax,ay;
int a[104][104];

vector<int> adj[100];
int visited[100];

// 1차원 2차원 변환이 난 아직 어려운듯?
void bfs(int here){
    queue<int> q;
    visited[here] = 1;
    q.push(here);

    while(q.size()){
        int here = q.front(); q.pop();

        for(int there : adj[here]){
            if(visited[there]) continue;
            visited[there] = visited[here] +1;
            q.push(there);
        }
    }
}


int main(){
    cin >> n >> m >> sx >> sy >> ax >> ay;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }



}