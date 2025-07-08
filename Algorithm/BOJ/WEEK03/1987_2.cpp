#include <bits/stdc++.h>
using namespace std;

int r, c, visited[21][21];
char a[21][21];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int mx = 0;

int b[26];

int bfs(int x, int y) {
    memset(visited, 0, sizeof(visited));
    memset(b, 0, sizeof(b));

    queue<pair<int, int>> q;
    q.push({x, y});

    while (!q.empty()) {

        
        tie(x, y) = q.front();
        q.pop();

        b[a[x][y] - 'A'] = 1;
        //str += a[x][y]; // 현재 정점에서의 문자 추가
        //cout << "현재 str은 " << str << '\n';

        visited[x][y] = 1;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            //cout << "현재 탐색하려는 글자는 " << a[nx][ny] << '\n';

            if (nx < 0 || nx >= r || ny < 0 || ny >= c || visited[nx][ny]) {
                //cout << "오버플로우라 넘김\n";
                continue;
            }
            // if (str.find(a[nx][ny]) != string::npos) {
            //     cout << a[nx][ny] << " 는 전에 들어온 글자라 넘김\n";
            //     continue;
            // }

            if(b[a[nx][ny] - 'A']) continue;

            //cout << "조건 만족해서 넣겠다!   \n";
            //b[a[nx][ny] - 'A'] = 1;
            visited[nx][ny] = visited[x][y] + 1;
            q.push({nx, ny});
            mx = max(mx, visited[nx][ny]);
        }
    }
    return mx;
}

int main() {
    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
        }
    }

    cout << bfs(0, 0);
}
