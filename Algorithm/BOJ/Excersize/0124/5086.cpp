#include <bits/stdc++.h>
using namespace std;

int a,b;

int main(){

    for(;cin >> a >>b ;){
        if( a<b && b%a == 0){
            cout << "factor" << '\n'; // 나머지 연산과 나누기 연산 다르다는거 ab 대소 비교 필요없음
        }else if(a>b && a%b == 0){
            cout << "multiple"<<'\n';
        }else if(a==0 && b== 0){
            break;
        }
        else{
            cout << "neither"<< '\n';
        }
    }
}