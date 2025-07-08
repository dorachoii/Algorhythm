#include <bits/stdc++.h>
using namespace std;

int n;
string s, ori_s, pre,suf;

int main(){

    cin >> n;
    cin >> ori_s;

    int pos = ori_s.find('*');

    pre = ori_s.substr(0,pos);
    suf = ori_s.substr(pos+1); // 두 번쨰 인자 안넣으면 끝까지 뽑아줌

    for(int i = 0; i <n; i++){
        cin >> s;

        if(pre.size() + suf.size() > s.size()){
            cout << "NE\n";             //반례도 꼭 !
        }else{
            if(pre==s.substr(0,pre.size()) && suf == s.substr(s.size()-suf.size()))
            cout << "DA\n";
            else cout << "NE\n";
        }
    }

}