#include <bits/stdc++.h>
using namespace std;

// 괄호에 넣는다 >> 스택에 쌓는다 연산 후 pop한다

int n;
string s;

int bracket(string s){
    string k = s;

    for(int i = 0; i < n-3; i+2){
        for(int j = i + 3; j < n;j+2 ){
           // 넣고 자르고, 그 뒤에꺼 또 수행하고 
           string bck = k.substr(i,j);
           ret
           bracket(bck);         
        }
    }
    ret += bracket(bck);
    // 최대 갱신해주는 로직
}

int main(){

    cin >> n >> s;

    bracket(s);
     
}