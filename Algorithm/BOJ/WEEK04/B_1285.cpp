#include <bits/stdc++.h>
using namespace std;

// 한 줄 뒤집기
// T 개수 세고 최소 갱신

int n, a[21][21], b[21][21], mnT= 403;
char s;

int check(){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(b[i][j] == 1) cnt++;
        }
    }

    return cnt;
}

int main(){

    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> s;
            if(s == 'H'){
                a[i][j] = 0;
                b[i][j] = 0;
            }
            else if (s == 'T'){
                a[i][j] = 1;
                b[i][j] = 1;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            b[i][j] ^= 1;

            //cout << "현재 a[i][j]는 " << a[i][j] <<'\n';
            //cout << "현재 b[i][j]는 " << b[i][j] <<'\n';

            mnT = min(check(), mnT);
            b[i][j] ^= 1;
            //cout << "mnT는 " << mnT <<'\n';
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            b[j][i] ^= 1;

            mnT = min(check(), mnT);
            b[j][i] ^= 1;
        }
        
    }

    cout << mnT -1;

}