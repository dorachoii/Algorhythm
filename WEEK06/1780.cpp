#include <bits/stdc++.h>
using namespace std;

int arr[1000004][1000004];
int minuss, zero, pluss;
int n;

void f(int x, int y, int n){

    // 변의 길이가 1
    if(n == 1){
        if(arr[x][y] == -1){
            minuss++;
        }else if(arr[x][y] == 0){
            zero++;
        }else{
            pluss++;
        }
    }

    bool isAllSame = true;
    int prevv = arr[x][y];

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            int crtI = i + x;
            int crtJ = j + y;

            if(arr[crtI][crtJ] != prevv){
                isAllSame = false;
            }
            
            prevv = arr[crtI][crtJ];
        }
    }

    if(isAllSame){
        if(arr[x][y] == -1){
            minuss++;
        }else if(arr[x][y] == 0){
            zero++;
        }else{
            pluss++;
        }
    }else{
        int newN = n/3;

        f(x, y, newN);
        f(x, y + newN, newN);
        f(x, y + newN + newN, newN);

        f(x + newN, y, newN);
        f(x + newN, y + newN, newN);
        f(x + newN, y + newN + newN, newN);

        f(x + newN + newN, y, newN);
        f(x + newN + newN, y + newN, newN);
        f(x + newN + newN, y + newN + newN, newN);
    }

    return;
}


int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    f(0,0,n);

    cout << minuss << '\n';
    cout << zero << '\n';
    cout << pluss << '\n';
}