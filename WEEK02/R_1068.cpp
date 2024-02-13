#include <bits/stdc++.h>
using namespace std;

//인접 리스트를 만드는데 양방향이 아니라, 자기 자식들만 담아
//지우고 남은 것 인접리스트가 0인 것들과 + 루트노드 1개?

int n,a[52],k,ret;
vector<int> adj[52];

bool b[52];

void cut(int node){
    b[node] = false;

    for(int s : adj[node]){
        cut(s);
    }
}

int main(){

    //입력 받기
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i]!=-1) adj[a[i]].push_back(i);
        b[i] = true;
    }
    cin >> k;
    if(a[k]= -1) ret = 0;

    // 노드 삭제
    else cut(k);

    for(int i = 0; i < n; i++){
        if(adj[i].size() == 0 && b[i] == true) ret++;
    }

    cout << ret;
}

//테스트 케이스 통과  but 틀림..