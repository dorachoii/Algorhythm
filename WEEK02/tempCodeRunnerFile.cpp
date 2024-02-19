#include <bits/stdc++.h>
using namespace std;

int n, m, u,v;

vector<pair<int,int>> ret;
vector<int> computerN;

vector<int> adj[10004];
bool visited[10004];

int hack(int node){
    int cnt= 0;
    visited[node] = true;

    for(int i = 0; i < adj[node].size(); i++){
        if(visited[adj[node][i]]) continue;
        hack(adj[node][i]);
        cnt++;
    }
    return cnt;
}

int main(){
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        cin >> v >> u;
        adj[u].push_back(v);
    }

    int prevv = -1;

    for(int i = 0; i < n; i++){

        if(!visited[i]){
            ret.push_back({hack(n), i});
        }
    }

    sort(ret.begin(), ret.end());

    int i = 1;
    while(ret[0].first == ret[i].first){
        computerN.push_back(ret[i].second);
        i++;
    }

    sort(computerN.begin(), computerN.end());

    for(int a : computerN) cout << a << " ";

}

