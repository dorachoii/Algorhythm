#include <iostream>
using namespace std;

int n, a[21][21];

int check() {
    int cnt = 0;
    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 1) // 'H'를 0으로 표시하고 있으므로 0인 경우를 세어야 함
                cnt++;
        }
    }
    return cnt;
}

int main() {
    cin >> n;
    int mnT = 987654321;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char s;
            cin >> s;
            if (s == 'T') // 'T'일 때만 1로 설정
                a[i][j] = 1;
            else // 그 외에는 모두 'H'이므로 0으로 설정
                a[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] ^= 1; // 해당 동전 뒤집기
            mnT = min(mnT, check());
            a[i][j] ^= 1; // 다시 원래대로 되돌리기
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[j][i] ^= 1; // 해당 동전 뒤집기
            mnT = min(mnT, check());
            a[j][i] ^= 1; // 다시 원래대로 되돌리기
        }
    }

    cout << mnT;

    return 0;
}
