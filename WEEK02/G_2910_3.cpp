#include <bits/stdc++.h>
using namespace std;

// 자료구조가 너무 헷갈림 모르겠음.. 2차원배열로 하는 것도 어렵고
// map으로 해도 key값으로 순차정렬이 되어버림..ㅠ

int n, c, a[1004];

map <int,int> mp;
vector<pair<int,int>> vecmp;

int main(){

    cin >> n >> c;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }

    for(int i = 0; i < n; i++){
        vecmp.push_back(<mp[a[i]].f>);// 이렇게 하려니 너무 여러개가 들어갔었꾸나.
    };

    int mx = 0;

    // map의 value에 접근하고 싶음
    for(auto& p : mp){
        mx = max(p.second, mx);
    }

    while(mx >0){

        for(auto& p : mp){
            if(p.second == mx){
                for(int i = 0; i < mx; i++){
                    cout << p.first << " ";
                }
            }
        }

        mx--;
    }



}