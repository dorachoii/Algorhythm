#include <bits/stdc++.h>
using namespace std;

int x[3], y[3];
int xx,yy;

// 3개 중 다른 하나를 골라내는 로직

int main(){

    cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2];

    if(!(x[0]^x[1])){
        xx = x[2];
    }else{
        if(x[0]^x[2]){
            xx = x[0];
        }else{
            xx = x[1];
        }
    }

    if (!(y[0] ^ y[1]))
    {
        yy = y[2];
    }
    else
    {
        if (y[0] ^ y[2])
        {
            yy = y[0];
        }
        else
        {
            yy = y[1];
        }
    }

    cout << xx << " " << yy;
}