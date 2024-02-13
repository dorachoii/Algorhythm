#include <bits/stdc++.h>
using namespace std;

vector<int> a[1001];
bool visited[1001];

void dfs(int node){
    visited[node] = true;
    cout << node << " ";

    for(int i = 0; i < a[node].size(); i++){
        int next = a[node][i];

        if(visited[next]== false){
            dfs(next);
        }
    }
}

void bfs(int start){
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout  << node << " ";

        for(int i = 0; i < a[node].size(); i++){
            int next = a[node][i];
            if(visited[next]==false){
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main(){
    int n,m,start;
    cin >> n >> m >> start;

    for(int i = 0; i < m; i++){
        int u,v;
        cin>> u >> v;

        a[u].push_back(v);
        a[v].push_back(u);
    }

    for(int i = 1; i <=n; i++){
        sort(a[i].begin(), a[i].end());
    }

    dfs(start);
    cout <<'\n';

    memset(visited, false, sizeof(visited));    //초기화해주는 것
    bfs(start);
    return 0;

}