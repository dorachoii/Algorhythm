#include <bits/stdc++.h>
using namespace std;

int n,x,y;

int space[101][101];
int cnt;

//중복뺴고 가로 세로 배열 만들어 1씩 더하는 로직으로 가보자

int main(){

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> x >> y;

        for(int j = x; j < x+10; j++){
            for(int k = y; k < y + 10; k++){                
                space[j][k] = 1;
            }
        }
    }

    for(int i = 0; i < 101; i++){
        for(int j = 0; j < 101; j++){

            if(space[i][j]== 1){
                cnt++;
            }
        }
    }

    cout << cnt;
}