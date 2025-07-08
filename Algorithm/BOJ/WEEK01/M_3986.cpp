#include <bits/stdc++.h>
using namespace std;

//항상 안되는 경우가 많을까? 되는 경우가 많을까?를 생각해서 더 적은 걸 구해 전체에서 빼는 방법 생각!

//일단 글자수가 짝수여야 한다.
// A,B의 개수가 모두 짝수여야 한다.
// 완벽대칭이니?
// 나열이니?

string s;
int n, cnt;


int main(){

cin >> n;

for(int i = 0; i < n; i++){
    cin >> s;
    if(s.size()%2 ==1){
        continue;
    }else{
        if(s.size()==2){
            if(s[0]== s[1]) cnt++;
            else continue;
        }else{
            if(s.find("ABAB")!=string::npos)continue;
            else cnt++;
        }
    }
}

cout <<cnt;
}