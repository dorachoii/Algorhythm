#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int r, c;
vector<vector<char>> arr;         
vector<vector<bool>> visited;

bool bfs(int startY, int startX, int endY, int endX) {
    queue<pair<int, int>> q;
    visited[startY][startX] = true;
    q.push({startY, startX});

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        if (y == endY && x == endX) return true;

        for (int d = 0; d < 4; d++) {
            int ny = y + dy[d];
            int nx = x + dx[d];

            if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
            if (arr[ny][nx] == '#' || visited[ny][nx]) continue;

            visited[ny][nx] = true;
            q.push({ny, nx});
        }
    }

    return false;
}

int main() {
    int n;
    cin >> r >> c >> n;

    pair<int, int> start, end;
    cin >> start.first >> start.second >> end.first >> end.second;

    arr = vector<vector<char>>(r, vector<char>(c));             // ← 고침
    visited = vector<vector<bool>>(r, vector<bool>(c, false));

    for (int i = 0; i < r; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < c; j++) {
            arr[i][j] = s[j];
        }
    }

    cout << bfs(start.first - 1, start.second - 1, end.first - 1, end.second - 1);
}
