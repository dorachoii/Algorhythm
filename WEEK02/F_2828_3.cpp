#include <bits/stdc++.h>
using namespace std;

// 슬라이딩 윈도우 도전 근데 안댐

// input
int n,m,j,k;

// moving
int prevN,nextN,frontB,rearB;

// result
int cnt;

int main(){
    cin >> n >> m >> j >>k ;
    prevN = k;
    
    frontB = 1;
    rearB = m;

    for(int i = 0; i < j-1; i++){
        cin >> nextN;

        if(rearB < nextN){
            //오른쪽 이동
            for(int i = rearB+1; i <=nextN; i++){
                rearB++;
                frontB++;
                cnt++;
            }

        }else if (frontB > nextN){
            //왼쪽 이동
            for(int i = frontB-1; i >= nextN; i--){
                frontB--;
                rearB--;
                cnt++;
            }
        }

        prevN = nextN;
    } 
    cout << cnt;
}