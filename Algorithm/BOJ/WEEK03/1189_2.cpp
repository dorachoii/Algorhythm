#include <iostream>
#include <cstring>
using namespace std;

int r, c, k, kcnt;
char a[6][6];
bool visited[6][6];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int x, int y, int dist) {
    if (x == 1 && y == c) { // 목표 지점에 도달한 경우
        if (dist == k) // 거리가 k와 일치하는지 확인
            kcnt++; // k와 일치하는 경우의 수 증가
        return;
    }

    visited[x][y] = true; // 현재 위치를 방문했다고 표시

    // 상하좌우로 이동
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 범위를 벗어나거나 이동할 수 없는 지역인 경우 continue
        if (nx <= 0 || nx > r || ny <= 0 || ny > c || a[nx][ny] == 'T' || visited[nx][ny])
            continue;

        dfs(nx, ny, dist + 1); // 다음 위치로 이동하며 거리를 1 증가시킴
    }

   // visited[x][y] = false; // 백트래킹
}

int main() {
    cin >> r >> c >> k;

    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            cin >> a[i][j];

    //memset(visited, false, sizeof(visited)); // visited 배열 초기화

    //kcnt = 0; // 경우의 수 초기화
    dfs(r, 1, 0); // DFS 시작

    cout << kcnt << endl; // 결과 출력

    return 0;
}
