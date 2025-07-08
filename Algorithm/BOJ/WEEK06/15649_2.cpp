#include <bits/stdc++.h>
using namespace std;

vector<int> V;  // 거쳐온 경로

int visited[10];
int N,M;

void f(int phase){  // phase: 단계

    if(phase == M){
        for(auto it : v){
            cout << it <<" ";
        }
        cout << '\n';
        return;
    }

    for(int i = 1; i <= N; ++i){
        if(visited[i]) continue;

        visited[i] = 1;
        v.push_back(i);
        f(phase +1);

        // 다시 초기화!
        v.pop_back();
        visited[i] = 0;
    }
}

int main(){
    cin >> N >> M;
    f(0);
}