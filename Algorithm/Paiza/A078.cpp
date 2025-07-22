#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

int h;
const int w = 5;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

vector<vector<char>> grid;
vector<vector<bool>> visited;
vector<pair<int, int>> chunk;

bool check(char a, int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;;
        if (grid[nx][ny] != a) return false;
    }
    return true;
}

void dfs(char a, int x, int y) {
    visited[x][y] = true;
    chunk.push_back({x, y});

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
        if (grid[nx][ny] != a || visited[nx][ny]) continue;
        dfs(a, nx, ny);
    }
}

void eraseChunk() {
    for (auto [x, y] : chunk) {
        grid[x][y] = '.';
    }
}

void drop() {
    for (int col = 0; col < w; ++col) {
        int target_row = h - 1;
        for (int row = h - 1; row >= 0; row--) {
            if (grid[row][col] != '.') {
                grid[target_row][col] = grid[row][col];
                if (target_row != row)
                    grid[row][col] = '.';
                target_row--;
            }
        }
        for (int row = target_row; row >= 0; row--) {
            grid[row][col] = '.';
        }
    }
}

int main() {
    cin >> h;
    grid = vector<vector<char>>(h, vector<char>(w));

    for (int i = 0; i < h; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < w; j++) {
            grid[i][j] = s[j];
        }
    }

    // 반복
    while (true) {
        bool exploded = false;
        visited = vector<vector<bool>>(h, vector<bool>(w, false));

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (isdigit(grid[i][j]) && !visited[i][j] && check(grid[i][j], i, j)) {
                    chunk.clear();
                    dfs(grid[i][j], i, j);
                    eraseChunk();
                    exploded = true;
                }
            }
        }

        if (!exploded) break;
        drop();  // 한 번만 호출
    }

    // 출력
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << grid[i][j];
        }
        cout << '\n';
    }

    return 0;
}
