#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e6;
bool isErased[MAX_N + 1];

int m, n;

int main(){
    cin >> m >> n;

    isErased[0] = true;
    isErased[1] = true;

    for(int p = 2; p * p <= n; ++p){
        if(isErased[p]) continue;
        
        for(int j = p * p; j <= n ; j+= p){
            isErased[j] = true;
        }
    }

    for(int i = m ; i <= n; i++){
        if(!isErased[i]) cout << i << '\n';
    }
}