#include <bits/stdc++.h>
using namespace std;

int n,p,k;
vector<int> adj[51];

bool dead[51];

void cut(int a){

    dead[a] = true;

    if (!adj[a].empty())
    {
        for(int j : adj[a]){

            if(dead[j]) continue;
            cut(j);
        }
    }
}

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> p;
        if(p == -1) continue;
        adj[p].push_back(i);
    }

    cin >> k;
    cut(k);

    int cnt = 0;
    for(int i = 0; i < n; i++){

        if(dead[i]) continue;
        if(!adj[i].empty()) continue;

        cnt++;
    }

    cout << cnt;



}
// 테스트케이스 통과