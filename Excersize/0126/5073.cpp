#include <bits/stdc++.h>
using namespace std;
int a, b, c;

int main (){
    while(cin >> a>>b>>c ){
        if(a==0) break;
        //if(!a)break;

        int s[] = {a,b,c};
        sort(s,s+3);

        if(s[0]+s[1]<=s[2]){
            cout << "Invalid"<<'\n';
        }else{
            if(a == b && b ==c){
                cout << "Equilateral" << '\n';
            }else if(a==b || b==c|| c==a){
                cout << "Isosceles" << '\n';
            }else{
                cout << "Scalene" << '\n';
            }
        }
    }
}