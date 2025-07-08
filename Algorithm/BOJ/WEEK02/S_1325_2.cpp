#include <bits/stdc++.h>
using namespace std;

int n, m, u,v;

vector<pair<int,int>> ret;
vector<int> computerN;

vector<int> adj[10004];
bool visited[10004];

int hack(int node){
    int cnt= 0; //위치 수정
    visited[node] = true;

    for(int i = 0; i < adj[node].size(); i++){
        if(visited[adj[node][i]]) continue;
        cnt += hack(adj[node][i]);
    }
    return cnt +1;
}

bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second > b.second; // 두 번째 요소인 second를 기준으로 내림차순 정렬
}

int main(){
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        cin >> v >> u;
        adj[u].push_back(v);
    }

    for(int i = 1; i <= n; i++){

        if(!visited[i]){
            ret.push_back({hack(i), i});
        }
    }

    sort(ret.begin(), ret.end(), compare);

    int i = 0;
    while(ret[0].first == ret[i].first){
        computerN.push_back(ret[i].second);
        i++;
    }

    sort(computerN.begin(), computerN.end());

    for(int a : computerN) cout << a << " ";

}

