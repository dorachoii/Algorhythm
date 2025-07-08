#include <bits/stdc++.h>
using namespace std;
int n, cnt;


int main(){
    cin >> n;

    for(int i = 666; i < INT_MAX; i++){
        string k = to_string(i);   //숫자를 문자로 변환하는 법

        if(k.find("666")!=string::npos) cnt++;
        if(cnt == n) {
            cout << i;
            break;
        }
    }

}