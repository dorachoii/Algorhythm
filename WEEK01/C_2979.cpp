#include <bits/stdc++.h>
using namespace std;
//min, max 구해서 배열
//cnt ++
// 1이라면 A, 2라면 B, 3이라면 C 곱해서 sum구하는 로직

int A,B,C;
int a,b;
int minn = 1,maxx,sum;

int t[101];

int main(){

    cin >> A >> B >> C;

    for(int i = 0; i < 3; i++){
        cin >> a >> b;

        if(a < minn) minn = a;
        if(b > maxx) maxx = b;

        for(int j = a; j < b; j++){
            t[j]++;
        }
    }

    for(int i = minn ; i <= maxx; i++){
        if(t[i] == 1){
            sum += A;
        }else if(t[i] == 2){
            sum += 2*B;
        }else if(t[i] == 3){
            sum += 3*C;
        }
    }

    cout << sum;

    
}