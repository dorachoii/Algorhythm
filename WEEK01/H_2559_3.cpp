#include <bits/stdc++.h>
using namespace std;

// 구간합으로 구해보기
int N,K;
int a[100004],psum[100004],ret[100004];


int main(){

    cin >> N >> K;

    for(int i = 1; i <=N; i++){
        cin >> a[i];
        psum[i] = psum[i-1] + a[i];
    }

    for(int i = 0; i <N-K+1; i++){
        ret[i] = psum[i+K] - psum[i];
    }

    sort(ret,ret+N-K+1);

    cout << ret[N-K];

}