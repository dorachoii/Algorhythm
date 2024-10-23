// 백트래킹: 뒤로 다시 돌아가서 확인해본다! 역으로 돌아가본다!
// 백트래킹을 곧 dfs라고 할 수 있다!

#include <bits/stdc++.h>
using namespace std;

// 거쳐온 경로
vector<int> v;

int visited[10];
int N,M;

// 리프노드에 왔는지 체크를 phase ,단계
void f(int phase){

    if(phase == M){
        for(auto it:v){
            cout << it <<" ";
        }
        cout << '\n';
        return;
    }

    for(int i = 1; i <= N; i++){
        if(visited[i]) continue;

        visited[i] = 1;
        v.push_back(i);
        f(phase + 1);

        // 다시 초기화!
        v.pop_back();
        visited[i] = 0;
    }
}

int main(){
    cin >> N>> M;
    f(0);
}