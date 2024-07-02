#include <bits/stdc++.h>
using namespace std;
int t,a,b;
vector<pair<int, int>> v;
int crtT;

int main(){
    cin >> t;

    for(int i = 0; i < t; i++){
        cin >> a >> b;
        v.push_back({a,b});
    }

    sort(v.begin(), v.end());

    crtT = v[0].first;

    for(pair<int, int> p : v){
        if(crtT < p.first){
            crtT = p.first;
        }

        for(int i = 0 ; i < p.second; i++){
            crtT++;
        }
    }

    cout << crtT;
    
}