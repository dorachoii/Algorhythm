#include <iostream>
#include <vector>
using namespace std;


// 블럭 연결 정보 [상, 하, 좌, 우]
int directions[6][4] = {
    {0, 0, 1, 1}, // 1: 가로 ─
    {1, 1, 0, 0}, // 2: 세로 │
    {1, 0, 0, 1}, // 3: ㄴ
    {0, 1, 0, 1}, // 4: ㄴ (회전)
    {0, 1, 1, 0}, // 5: ㄱ
    {1, 0, 1, 0}  // 6: ㄱ (회전)
};

// 상, 하, 좌, 우
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

// 방향 일치 여부 확인 함수
bool matchDirection(const vector<vector<int>>& arr, int y, int x, int blockType) {
    for (int d = 0; d < 4; d++) {
        int ny = y + dy[d];
        int nx = x + dx[d];
        if (ny < 0 || nx < 0 || ny >= arr.size() || nx >= arr[0].size()) continue;
        int neighbor = arr[ny][nx];
        if (neighbor >= 1 && neighbor <= 6) {
            int opposite = d ^ 1; // 0↔1, 2↔3
            if (directions[blockType][d] != directions[neighbor - 1][opposite]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    string s;

    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) {
            arr[i][j] = s[j] - '0';
        }
    }

    // 7인 위치 찾아서 적절한 블록 넣기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 7) {
                for (int type = 0; type < 6; type++) {
                    if (matchDirection(arr, i, j, type)) {
                        arr[i][j] = type + 1; // 1~6
                        break;
                    }
                }
            }
        }
    }

    // 결과 출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j];
        }
        cout << '\n';
    }

    return 0;
}
