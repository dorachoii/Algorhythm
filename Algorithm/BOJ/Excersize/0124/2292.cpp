#include <bits/stdc++.h>
using namespace std;

int bee(int n){
    if(n == 1 ) return 1;
    return (n-1) * 6 + bee(n-1);
}

int k,n;

int main(){

    cin >>k;

    for(int i = 1; i < 20000; i++){
        if(k <= bee(i)){    //범위 잘 보기
            n=i;
            break;
        }
    }
    
    cout << n <<'\n';
    //cout << bee(20000); * 범위 한정하는 방법..

}