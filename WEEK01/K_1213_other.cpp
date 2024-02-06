#include <bits/stdc++.h>
using namespace std;

string s, ret;
int cnt[200], flag;
char mid;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;

    for (char a: s) cnt[a]++;

    for(int i = 'Z'; i >= 'A'; i--){
        if(cnt[i]){
            if(cnt[i]&1){   //홀수인지 체크
                mid = char(i); flag++;
                cnt[i]--;
            }

            if(flag == 2) break;

            for(int j = 0; j < cnt[i]; j+=2){
                ret = char(i) + ret;
                ret += char(i);
            }
        }
    }

    if(mid)ret.insert(ret.begin() + ret.size()/2,mid);//insert하면 되는 구나
    // 빼주다가 1되면 마지막에 넣는 거?
    // 나랑 홀수가 1개가 아닌 경우 어떻게 다르게 처리했는지.
    
    if(flag==2) cout << "I'm Sorry Hansoo\n";
    else cout << ret << "\n";

}