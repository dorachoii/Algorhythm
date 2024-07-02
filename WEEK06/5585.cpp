#include <bits/stdc++.h>
using namespace std;

// 그리디
// 항상 동전문제가 그리디인것은 아니다!
// 7원, 5원, 1원, 10원 -> 7원 사용이 항상 최적은 아님!
// 배수일 때 그리디를 사용할 수 있다!

// 1931 회의실 배정까지는 본 적있음!
// 가장 빨리 끝나는걸 넣는것이 이득!




int num, cnt = 0;
int a[6] = {500, 100, 50, 10, 5, 1};

int main(){
    
    cin >> num; 
    num = 1000 - num;

        for(int i = 0; i < 6; i++){ 
        cnt += num / a[i]; 
        num = num % a[i]; 
    }
    
    cout << cnt; 
}
