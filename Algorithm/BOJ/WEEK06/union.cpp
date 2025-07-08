// 코테 통과는 백트래킹까지만 알면되고! 유니온 파인드 부터는 킬러 문항으로 나옴!

// Union은 합집합, Find: 그룹의 대표찾기!

// DP기법의 두 가지 기법 중 하나로, 메모리자이제이션?

#include <bits/stdc++.h>
using namespace std;

int n, m;
int par[1000001];
// 0: 합집합, 1: Find 
// 대표를 리턴하는 연산

void init(){
    // 모든 노드가 자기 자신으로 초기화
    for(int i = 0; i <1000001; ++i){
        par[i] = i;
    }
}

int Find(int x){
    // 그룹 대표 찾기, 
    if(x==par[x]) return x;
    return par[x] = Find(par[x]); // 이 결과를 날아가지 않게 저장하면 된다!
}

void Union(int a, int b){
    int A = Find(a);
    int B = Find(b);

    par[A] = B;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    init();
    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        int ch, a, b; cin >> ch >> a >> b;

        if(ch == 0){
            Union(a,b);
        }else{
            if(Find(a) == Find(b)){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
        }
    }
}