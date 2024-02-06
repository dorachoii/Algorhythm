#include <bits/stdc++.h>
using namespace std;

const int V = 10;
vector<int> adj[V];
bool visited[V];

void go(int from){
    visited[from] = 1;
    cout << from << '\n';

    for(int i = 0; i < V; i++){
        if(visited[i])continue;
        
        for(int j = 0; j < adj[i].size(); j++){
            if(visited[adj[i][j]]){
                go(j);
                break;
            }
        }
    }
}


int main(){
    adj[1].push_back(2);
    adj[1].push_back(3);

    adj[3].push_back(4);

    for(int i = 0; i < V; i++){
        go(i);
    }
}
