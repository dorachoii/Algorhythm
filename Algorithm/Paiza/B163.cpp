#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int h, w;
vector<vector<int>> v;
vector<vector<bool>> visited;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dfs(int x, int y) {
    visited[x][y] = true;
    int cnt = 1;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
        if (v[nx][ny] == 1 && !visited[nx][ny]) {
            cnt += dfs(nx, ny);
        }
    }
    return cnt;
}

int main() {
    cin >> h >> w;
    string s;
    v.resize(h);
    visited.assign(h, vector<bool>(w, false));

    for (int i = 0; i < h; i++) {
        cin >> s;
        for (int j = 0; j < w; j++) {
            v[i].push_back(s[j] - '0');
        }
    }

    int maxArea = 0;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (v[i][j] == 1 && !visited[i][j]) {
                maxArea = max(maxArea, dfs(i, j));
            }
        }
    }

    cout << maxArea << endl;
}
