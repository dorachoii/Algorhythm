#include <bits/stdc++.h>
using namespace std;

//순열 구현
//1. do while
//2. 직접 재귀함수 만드는 방법

int a[9];
int n = 9, r =7;

void solve(){
    int sum = 0;

    for(int i = 0; i<r; i++){
        sum+=a[i];
    }

    if(sum==100){
        sort(a,a+7);
        for(int i = 0; i < r; i++) cout << a[i] << "\n";
        exit(0);    // return 과의 차이 : return solve함수 종료, exit main함수 종료
    }   
}

void print(){
    for(int i = 0; i < r; i++) cout << a[i] << " ";
    cout << '\n';
}

void makePermutation(int n, int r, int depth){  // 이 함수는 외우고 있어야 함.
    if(r == depth){
        print();//  제대로 뽑았는지 확인
        solve();
        return; // 재귀함수일 때 기저사례 중요!
    }

    for(int i = depth; i < n; i++){
        swap(a[i],a[depth]);
        makePermutation(n,r,depth +1);
        swap(a[i], a[depth]);
    }

    return;
}

 
int main(){

    for(int i = 0; i < n ; i++){
        cin >> a[i];
    }

    makePermutation(n,r,0);
    return 0;

}