#include <bits/stdc++.h>
using namespace std;

int a,b;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

long long lcm(int a, int b){
    return a/gcd(a,b) *b;
}

int main(){

    cin >> a >> b;

    cout << gcd(a, b) <<'\n';
    cout << lcm(a , b);
       
}