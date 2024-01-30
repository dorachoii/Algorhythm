#include <bits/stdc++.h>
using namespace std;

string s;

int main(){
    // 내 코드 26 뺴주는 거 A를 빼주는 게 아니라.
    // %도 알아두기!

    getline(cin,s);

    for(int i = 0; i < s.size(); i++){
        //대문자인 경우
        if(s[i] >= 65 && s[i] <97){
            if(s[i] + 13>90) s[i] = s[i] + 13-26;
            else s[i] = s[i] + 13;
        }else if(s[i]>=97 && s[i] <=122){
            if(s[i] + 13 >122) s[i] = s[i] + 13 -26;
            else s[i] = s[i] +13;
        }
    }


}