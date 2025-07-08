#include <bits/stdc++.h>
using namespace std;

const int V = 4;
vector<int> adj[V]; // list가 아닌 vector로도 구현할 수 있다. 편의상 vector로 구현하겠음
//정점마다 연결리스트가 필요하니까, 4개의 벡터가 있는 것.

int main(){

    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[0].push_back(3);

    adj[1].push_back(0);
    adj[1].push_back(2);

    adj[2].push_back(0);
    adj[2].push_back(1);

    for(int i = 0; i < 4; i++){
        cout << i << " :: ";

        for(int there : adj[i]){
            cout << there << " ";
        }
        cout << '\n';
    }
}