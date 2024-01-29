#include <bits/stdc++.h>
using namespace std;

int a[26],cnt;
string str;

int main(){

    cin >> str;

    for(int i = 0; i < 26; i++){
        cnt = 0;
        for(char c : str) {
            
            if(c=='a'+i) cnt++;
        }
        a[i] = cnt;
    }

    for(int b : a){
        cout << b << " ";
    }

}