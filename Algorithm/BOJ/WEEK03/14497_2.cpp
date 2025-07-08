#include <bits/stdc++.h>
using namespace std;

#define y1 aaa

int n, m, x1, x2, y1_, y2; // y1을 y1_로 변경

char a[303][303];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
int cnt = 0;

void dfs(int x, int y) {
    // 이미 방문한 곳을 표시
    a[x][y] = '0';

    // 해당 영역의 탐색을 마쳤으므로 카운트 증가
    cnt++;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 올바른 범위 내에 있고, 아직 방문하지 않았고, 벽이 아니라면 재귀 호출
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] != '#' && a[nx][ny] != '0') {
            dfs(nx, ny);
        }
    }
}

int main() {
    cin >> n >> m >> x1 >> y1_ >> x2 >> y2; // y1을 y1_로 변경

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    dfs(x1, y1_);

    cout << cnt;
}
