#include <bits/stdc++.h>
using namespace std;

int n, cnt;
long long sqr = 1;

int main(){
    cin >> n;

    for(int i = 1; i<= n; i++){
        if(i%5 == 0){
            cnt++;
        }
        sqr *= i;
    }

    cout << cnt ;
}

// 최대공약수 : 빼기로 구현!
// 큰쪽에서 작은쪽 빼기 