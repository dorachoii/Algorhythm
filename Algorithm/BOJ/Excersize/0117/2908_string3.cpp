#include <bits/stdc++.h>
using namespace std;

string a,b;
int c,d;

int main(){

    cin >> a >> b;

    char t;

    t = a[0];
    a[0] = a[2];
    a[2] = t;

    t = b[0];
    b[0] = b[2];
    b[2] = t;

    c = stoi(a);
    d = stoi(b);

    if(c>=d){
        cout << c<<'\n';
    }else{
        cout << d<<'\n';
    }

    // * 삼항연산자 활용: c>d ? c:d;

    return 0;

}