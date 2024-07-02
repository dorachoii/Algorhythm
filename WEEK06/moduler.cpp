#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll n , p, mul = 1;

int main(){
    cin >> n >> p;
    
    for(ll i = 1; i <= n; i++){
        mul *= i;
        mul %= p;
    }
    
    cout << mul % p;
}