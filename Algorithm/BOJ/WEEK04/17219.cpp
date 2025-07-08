#include <bits/stdc++.h>
#include <iostream>

using namespace std;

    int n, m;
    map<string, string> mp;
    string s, ss;

int main(){

    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> s >> ss;
        mp[s] = ss;
    }


    for(int i = 0; i < m; i++) {
        cin >> s;
        cout << mp[s] << '\n';
    }
}