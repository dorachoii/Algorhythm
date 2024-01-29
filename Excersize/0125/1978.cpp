#include <bits/stdc++.h>
using namespace std;

int T,N;
int cnt = 0;

int main(){
    cin >> T;

    for(int i = 0; i<T; i++){
        cin >> N;
        //cout << "현재 N은 " << N << '\n';

        if(N==1) cnt--;

        for(int j = 2; j< N; j++){
            if(N%j == 0) {
                cnt--;
                break;
            }
        }
        cnt++;  
        //cout << "현재 cnt는 " << cnt << '\n';      
    }

    cout << cnt;
}

// 약수 개수가 2이면 cnt ++해주는 방식
// prime bool 값 활용하는 방법