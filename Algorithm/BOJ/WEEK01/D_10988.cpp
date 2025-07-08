#include <bits/stdc++.h>
using namespace std;

string str;

int main(){

    cin >> str;

    string r = str;
    reverse(r.begin(), r.end());

    if(str==r) cout << 1;
    else cout << 0;

}