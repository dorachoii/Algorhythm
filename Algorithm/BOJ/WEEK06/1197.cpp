#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>


using namespace std;
using ll=long long;
using pii=pair<ll,ll>;


vector<pii> G[10001];
ll par[10001];

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

void init(){
    for(ll i=0; i<10001; ++i){
        par[i]=i;
    }
}

struct Edge {
    ll u, v, w;
};

vector<Edge> edges;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    init();
    ll V, E; cin>>V>>E;
    for(ll i=0; i<E; ++i){
        ll A, B, C; cin>>A>>B>>C;
        edges.push_back({A,B,C});
    }
    sort(edges.begin(), edges.end(), [](Edge a, Edge b){
        return a.w<b.w;
    });
    ll res=0;

    for(auto edge:edges){
        ll u=edge.u;
        ll v=edge.v;
        ll w=edge.w;

        if(Find(u)==Find(v)){
            continue;
        }

        Union(u, v);
        res+=w;
    }

    cout << res << '\n';
}