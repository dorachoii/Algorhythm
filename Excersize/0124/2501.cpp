#include <bits/stdc++.h>
using namespace std;

int N,K;
vector<int> n;

int main(){
    cin >> N >> K;

    for(int i = 1; i <= N; i++){
        if(N%i==0) n.push_back(i);
    }

    if(K <= n.size()){
        cout << n[K - 1];
    }else{
        cout << 0;
    }
    
    
}