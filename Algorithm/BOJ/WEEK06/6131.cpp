// 브루트포스 : 긁기?
// 답의 범위를 전부 돌아본다!

// 브루트포스인지 판별 후에 n범위를 보고 다른 거 생각!
// N, M이 수상하게 작다..

// 문자열 파싱 : 파이선이 훨씬 쉬움! 언어별 편차가 크다!
// swift JSONDecoder

#include <bits/stdc++.h>
using namespace std;
int N, cnt;

int main(){
    cin >> N;

    for(int a = 1; a <= 500; a++){
        for(int b = 1; b <= 500; b++){
            if((a-b)*(a+b)== N){
                cnt++;
            }
        }
    }
    
    cout << cnt;
}