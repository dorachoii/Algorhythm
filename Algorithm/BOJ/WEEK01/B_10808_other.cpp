#include <bits/stdc++.h>
using namespace std;

// counting star는 맵 또는 배열
// map <key: value>
// 1. 맵을 써야 할 때 : string 기반으로 할 때
// 2. 배열을 써야 할 때 : integer 기반으로 할 때

// sparse : 희소하다 vs dense: 밀집
// 문자를 카운팅하는 것이므로 배열 사용 (아스키코드)
// 65,97

string str;
int cnt[26];    //세는 것은 cnt로 하기

int main(){

    cin >> str;
    
    for(char a : str){
        cnt[a -'a'] ++; // 좌표 이동, 평행 이동
    }

    for(int i = 0; i < 26; i++) cout << cnt[i] << " ";

    return 0;
}