#include <bits/stdc++.h>
using namespace std;

int n, a[21][21], b[21][21];
char s;

int check(){
    int cnt = 0;

    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] == 1) cnt++;
        }
    }

    return cnt;
}

int main(){
    cin >> n;
    int mnT = 987654321;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> s;
            if(s == 'H'){
                a[i][j] = 0;
            }
            if(s == 'T'){
                a[i][j] = 1;
            }   
        }
    }

    for(int i = 0; i < n; i++){
        for(int j= 0; j < n; j++){

            // ^= 같으면 0, 다르면 1을 반환
            a[i][j] ^= (1 << 1);
            mnT = min(mnT, check());
            a[i][j] ^= (1 << 1);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j= 0; j < n; j++){

            // ^= 같으면 0, 다르면 1을 반환
            a[j][i] ^= (1 << 1);
            mnT = min(mnT, check());
            a[j][i] ^= (1 << 1);
        }
    }

    cout << mnT;

}