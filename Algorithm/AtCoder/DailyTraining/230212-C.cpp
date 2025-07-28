#include <iostream>
#include <vector>
#include <deque>
#include <tuple>
#include <set>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int r, c, n;
vector<string> board;

bool inRange(int y, int x) {
    return 0 <= y && y < r && 0 <= x && x < c;
}

void stamp(int sy, int sx, vector<string>& b) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int ny = sy + i;
            int nx = sx + j;
            if (inRange(ny, nx)) {
                b[ny][nx] = '.';
            }
        }
    }
}

int bfs(int sy, int sx, int gy, int gx) {
    deque<tuple<int, int, int, vector<string>>> dq;
    set<tuple<int, int, vector<string>>> visited;

    dq.push_front({sy, sx, 0, board});
    visited.insert({sy, sx, board});

    while (!dq.empty()) {
        auto [y, x, cost, curBoard] = dq.front();
        dq.pop_front();

        if (y == gy && x == gx) return cost;

        for (int d = 0; d < 4; d++) {
            int ny = y + dy[d];
            int nx = x + dx[d];
            if (!inRange(ny, nx)) continue;

            // 그냥 이동
            if (curBoard[ny][nx] == '.') {
                if (visited.count({ny, nx, curBoard}) == 0) {
                    visited.insert({ny, nx, curBoard});
                    dq.push_front({ny, nx, cost, curBoard});
                }
            }
            // 벽이면 스탬프 후보 위치 탐색
            else if (curBoard[ny][nx] == '#') {
                for (int sy = ny - n + 1; sy <= ny; sy++) {
                    for (int sx = nx - n + 1; sx <= nx; sx++) {
                        if (!inRange(sy, sx) || !inRange(sy + n - 1, sx + n - 1)) continue;

                        vector<string> newBoard = curBoard;
                        stamp(sy, sx, newBoard);

                        if (newBoard[ny][nx] == '.') {
                            if (visited.count({ny, nx, newBoard}) == 0) {
                                visited.insert({ny, nx, newBoard});
                                dq.push_back({ny, nx, cost + 1, newBoard});
                            }
                        }
                    }
                }
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int sy, sx, gy, gx;
    cin >> r >> c >> n;
    cin >> sy >> sx >> gy >> gx;
    sy--, sx--, gy--, gx--;

    board.resize(r);
    for (int i = 0; i < r; i++) {
        cin >> board[i];
    }

    cout << bfs(sy, sx, gy, gx) << "\n";
    return 0;
}
