#include <bits/stdc++.h>
using namespace std;

int A,B,V;
int d = 1;

int main(){
    cin >> A >> B >> V;
    d += (V-A)/(A-B);

    if((V-A)%(A-B)!=0)d++;
    if(A >=V) cout << 1;
    else cout << d;

}
// https://cryptosalamander.tistory.com/22
// https://carrot-farmer.tistory.com/40