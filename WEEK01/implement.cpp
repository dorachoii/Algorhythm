#include <bits/stdc++.h>
using namespace std;

string str = "abcde";

int main(){

    // 3개 출력
    cout << str.substr(0,3) << '\n';

    // 거꾸로 출력
    reverse(str.begin(), str.end());
    cout << str << '\n';

    // 00 추가 출력
    cout << str + "00" << '\n';
    return 0;
}