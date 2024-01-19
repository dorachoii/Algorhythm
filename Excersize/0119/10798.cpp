#include <bits/stdc++.h>
using namespace std;

string T;
int a[5][15];


int main(){

    for(int i = 0; i<5;i++){
        cin >> T;

        for(int j = 0; j<T.length(); j++){
            a[i][j] = (int)T[i];
        }
    }

    for(int i = 0; i < 15; i++){
        string s;
        for(int j = 0; j < 5; j++){
            s+= (char)a[i][j];
        }
        cout << s << '\n';
    }
}