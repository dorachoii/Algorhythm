#include <bits/stdc++.h>
using namespace std;

int a[9][9];
int x,y,m = -1;      //max라는 네임스페이스가 있어서 충돌하는듯, 최대,최소 범위 잘 확인!

int main(){

    for(int i = 0; i <9; i++){
        for(int j = 0; j < 9; j++){
            cin >> a[i][j];

            if(a[i][j] > m){
                x = i+1;
                y = j+1;
                m = a[i][j];
            }        
        }
    }

    cout << m <<'\n';
    cout << x << " " << y;
}
