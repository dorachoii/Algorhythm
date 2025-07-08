#include <bits/stdc++.h>
using namespace std;
//split 써야 함 find 와

int n;
string s,tc;

vector<string> split(string input, string delimiter){
    vector<string> ret;
    long long pos = 0;
    string token = "";

    while((pos = input.find(delimiter))!=string::npos){
        token = input.substr(0,pos);
        ret.push_back(token);
        input.erase(0,pos+delimiter.length());
    }
    ret.push_back(input);
    return ret;
}

int main(){
    
    cin >> n >> s;

    vector<string> se = split(s,"*");

    for(int i = 0; i < n ; i++){
        cin >> tc;

        if(tc.find(se[0]) == 0 && tc.find(se[1])== tc.length() - se[1].length()) cout << "DA"<<'\n';
        else cout << "NE" <<'\n';
    }

}

// 1차 시도: 패턴이 3글자로 주어지는 줄 알고 s[0],s[2]와 비교
// 2차 시도: split이용해 앞,뒤 비교 -> 앞 패턴 뒤 패턴 같을 수도 있다는 것 고려하지 않음
