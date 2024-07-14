#include <bits/stdc++.h>
using namespace std;

int arr[130][130];

int white, blue;

void f(int x, int y, int n){

    if(n == 1){
        if(arr[x][y] == 0){
            white++;
        }else{
            blue++;
        }
    }

    bool isOne = true;
    bool isZero = true;

    //(x.y) 한 변이 n인 친구를 해결하겠다!
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            int ci = i +x;
            int cj = j +y;

            if(arr[ci][cj] == 0) isOne = false;
            if(arr[ci][cj] == 1) isZero = false;

            
        }
    }

    if(isZero){
        white++;
    }else if(isOne){
        blue++;
    }else{
        int newN = n/2;
        f(x,y,newN);
        f(x, y + newN, newN);
        f(x + newN, y, newN);
        f(x + newN, y + newN, newN);
    }

    return;
}

int main(){
    // 변의 길이가 1일 때까지 4분할
    // 걔가 모두 같다면 1개 cnt++

    // 아니면 4분할의 재귀

    int N; cin >> N;
    
    for(int i = 0; i< N; ++i){
        for(int j = 0; j < N; ++j){
            cin >> arr[i][j];
        }
    }

    f(0,0,N);

    cout << white <<'\n';
    cout << blue << '\n';

}