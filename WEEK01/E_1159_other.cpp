#include <bits/stdc++.h>
using namespace std;

int n, cnt[26];
string s, ret;

int main(){

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        cnt[s[0]-'a']++;
    }

    for(int i = 0; i < 26; i++) if(cnt[i] >=5) ret +=(i + 'a'); // char(i + 'a')라고 해야하지만 숫자도 문자화되어 

    ir(ret.size()) cout << ret << "\n";
    else cout << "PREDAJA" << "\n";

}