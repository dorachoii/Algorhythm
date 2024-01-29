#include <bits/stdc++.h>
using namespace std;

int a,b,c;

int main(){

    cin >> a >> b >> c;
    if(a+b+c != 180){
        cout << "Error";
    }else{
        if(a==b && b==c) cout << "Equilateral";
        else if((a==b && a!=c)||(a!=b && b==c)||(a==c && b!=c)) cout << "Isosceles";
        else cout << "Scalene";
    }

}