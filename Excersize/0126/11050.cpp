#include <bits/stdc++.h>
using namespace std;

int N,K;

int factorial(int n){
    if(n==1) return 1;
    return factorial(n-1)*n; 
}

int main(){

    cin >> N >> K;

    int ret = factorial(N) / (factorial(K)* factorial(N-K));
    cout << ret;


}