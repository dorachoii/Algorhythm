#include <bits/stdc++.h>
using namespace std;

int N,M;
int cnt;

int main(){

    cin >> N >> M;

    int a[N];

    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    
    if(N>1){
        for (int i = 0; i < N - 1; i++)
        {
            for (int j = i+1; j < N; j++)
            {
                if (a[i] + a[j] == M)
                    cnt++;
            }
        }
    }else{
        cnt = 0;
    }   
    cout << cnt;

}

// 시간 제한 어떻게 보는거지?
// N = 1일 때를 고려하지 않은 듯 하여 N>1로 막아줌
// 서로 다른 두 재료 아닌가?
// for문 돌릴 땐 인덱스 좀 제대로 확인하자.. 두번째 for문에서 i+1안해줘서 틀림 바보.. 항상 시각화해서 생각.