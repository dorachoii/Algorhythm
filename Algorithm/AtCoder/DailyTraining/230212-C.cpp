#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int r, c, n;
vector<vector<char>> arr;
vector<vector<bool>> visited;

void stamp(int y, int x)
{
    for (int i = y; i < y + n; i++)
    {
        for (int j = x; j < x + n; j++)
        {
            if (i < 0 || i >= r || j < 0 || j >= c)
                continue;
            arr[i][j] = '.';
        }
    }
}

int bfs(int startY, int startX, int endY, int endX)
{
    queue<pair<int, int>> q;
    visited.assign(r, vector<bool>(c, false)); // 방문 초기화 꼭 해주기
    visited[startY][startX] = true;
    q.push({startY, startX});
    int count = 0;

    while (!q.empty())
    {
        auto [y, x] = q.front();
        q.pop();

        if (y == endY && x == endX)
            return count;

        bool canMove = false;
        for (int d = 0; d < 4; d++)
        {
            int ny = y + dy[d];
            int nx = x + dx[d];

            if (ny < 0 || ny >= r || nx < 0 || nx >= c)
                continue;
            if (arr[ny][nx] == '#' || visited[ny][nx])
                continue;

            canMove = true;
            visited[ny][nx] = true;
            q.push({ny, nx});
        }

        if (!canMove)
        {
            // 상하좌우 중 막힌 곳 찾아서 찍는게 좋지만 일단 위쪽으로 고정
            for (int i = 0; i < 4; i++)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny < 0 || ny >= r || nx < 0 || nx >= c)
                    continue;

                if (arr[ny][nx] == '#')
                {
                    count++;
                    stamp(ny, nx);

                    visited[ny][nx] = true;
                    q.push({ny, nx});
                    break;
                }
            }
        }
    }

    return count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> c >> n;

    pair<int, int> start, end;
    cin >> start.first >> start.second >> end.first >> end.second;

    arr = vector<vector<char>>(r, vector<char>(c));
    for (int i = 0; i < r; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < c; j++)
        {
            arr[i][j] = s[j];
        }
    }

    cout << bfs(start.first - 1, start.second - 1, end.first - 1, end.second - 1) << "\n";

    return 0;
}

