#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

// 그래프를 트리로 표현하는 테크닉!

using namespace std;
using ll=long long;
using pii=pair<ll,ll>;

ll Find(ll x){
    if(par[x]==x) return x;
    return par[x]=Find(par[x]);
}

void Union(ll a, ll b){
    a=Find(a);
    b=Find(b);
    if(a==b) return;
    par[a]=b;
}

int n, m, x, y;
vector<pair<int,int>> co;

int main(){
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> x >> y;
        co.push_back({x,y});
    }

}