#include <bits/stdc++.h>
using namespace std;

string T;
int a[5][15];           //char로 저장해야했음

int main(){

    for(int i = 0; i<5;i++){
        cin >> T;

        for(int j = 0; j<T.length(); j++){
            a[i][j] = (int)T[j];
        }
    }


    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 5; j++){
            char s = (char)a[j][i];
            cout << s;
        }   
        cout <<'\n';   
    }
}