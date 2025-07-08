#include <bits/stdc++.h>
using namespace std;

int n, price[11][11], garden[11][11];
vector<pair<int, int>> co;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool blossom(int x, int y) {
    bool isDead = false;
    garden[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n || garden[nx][ny] == 1) {
            isDead = true;
        }
    }

    return !isDead;
}

int calculate() {
    int ret = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (garden[i][j] == 1) {
                ret += price[i][j];
            }
        }
    }

    return ret;
}

int main() {
    // 화단 너비 : n
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> price[i][j];
            co.push_back({i, j});
        }
    }

    int mn = 2000000;

    // 3개 spot고르기
    for (int i = 0; i < co.size(); i++) {
        for (int j = i + 1; j < co.size(); j++) {
            for (int k = j + 1; k < co.size(); k++) {

                memset(garden, 0, sizeof(garden));

                if (blossom(co[i].first, co[i].second) && blossom(co[j].first, co[j].second) && blossom(co[k].first, co[k].second)) {
                    //cout <<"꽃이 피었습니다\n";
                    mn = min(mn, calculate());
                }
            }
        }
    }

    cout << mn;

    return 0;
}

