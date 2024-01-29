#include <bits/stdc++.h>
using namespace std;

int N,k = 2;

int main(){

    cin >> N;

    if(N == 1) cout <<"";

    while(N != 1){

        if(N%k==0){
            cout << k << '\n';
            N = N/k;
        }else{
            k++;
        }
    }

}