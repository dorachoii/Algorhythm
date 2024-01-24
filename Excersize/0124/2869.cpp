#include <bits/stdc++.h>
using namespace std;
// 시간초과 해결
int A,B,V;

int h = 0,d = 0;

int main(){
    cin >> A >> B >> V;

    for(int i = 0; i <= V/(A-B); i++){
        h +=A;

        if(h >= V) {
            d++;
            break;
        }

        h-=B;
        d++;
    }

    cout << d;
}