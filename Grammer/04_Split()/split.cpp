#include <bits/stdc++.h>
using namespace std;

vector<string> split(string input, string delimiter){       //delimiter : 구분자
    vector<string> ret;
    long long pos = 0;
    string token = "";

    while((pos = input.find(delimiter)) != string::npos){
        token = input.substr(0,pos);                    //*substr : 문자열 자르기
        ret.push_back(token);                           //*push_back : 넣기
        input.erase(0,pos + delimiter.length());        //*erase(시작 위치, 길이)
    }

    ret.push_back(input);
    return ret;
}

int main(){

    string s= "어제는 비가 오고 오늘은 눈이 오고 내일은 해가 뜰까요?", d = " ";
    vector<string> a = split(s,d);
    for(string b : a) cout << b << "\n";

    string ss = "abcffabcdffabcdeff", dd = "ff";
    vector<string> aa = split(ss, dd);
    for (string b : aa)
        cout << b << "\n";

    return 0;
}