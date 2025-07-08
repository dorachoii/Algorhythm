#include <bits/stdc++.h>
using namespace std;

int N,B;
int k;

string num,K;

int main(){

    cin >> N >> B;

    while( N >= B){
       k = N % B;
    
        if(k > 9){
            K = 'A' + k -10;
        }else{
            K = to_string(k);
        }

        num += K;
        N /= B;
    }

    if(N>9){
        K = 'A' + N -10;
    }else{
        K = to_string(k);
    }
    num += K;

    reverse(num.begin(),num.end());

    cout << num;
}