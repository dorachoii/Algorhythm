#include <bits/stdc++.h>
using namespace std;

int n, m, a[51][51], b[51][51], visited[51][51];
vector<pair<int, int>> cPos;
vector<pair<int, int>> hPos;

int cnt;
int minCityCD = INT_MAX;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int bfs(int y, int x, vector<pair<int, int>> &chickens)
{
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> q;
    visited[y][x] = 1;
    q.push({y, x});
    int mn = INT_MAX;

    while (!q.empty())
    {
        tie(y, x) = q.front();
        q.pop();

        for (auto &chicken : chickens)
        {
            int ny = chicken.first, nx = chicken.second;
            int dist = abs(ny - y) + abs(nx - x);
            mn = min(mn, dist);
        }

        for (int i = 0; i < 4; ++i)
        {
            int ny = y + dy[i], nx = x + dx[i];
            if (ny < 1 || ny > n || nx < 1 || nx > n || visited[ny][nx] || a[ny][nx] != 0)
                continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }

    return mn;
}

void pick(int idx, int selected)
{
    if (selected > m)
        return;

    if (idx == cPos.size())
    {
        int cCnt = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (b[i][j] == 2)
                    ++cCnt;
            }
        }

        if (cCnt == m)
        {
            int cityCD = 0;
            for (auto &house : hPos)
            {
                cityCD += bfs(house.first, house.second, cPos);
            }
            minCityCD = min(minCityCD, cityCD);
        }

        return;
    }

    b[cPos[idx].first][cPos[idx].second] = 2;
    pick(idx + 1, selected + 1);
    b[cPos[idx].first][cPos[idx].second] = 0;
    pick(idx + 1, selected);
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
            if (a[i][j] == 1)
                hPos.emplace_back(i, j);
            if (a[i][j] == 2)
                cPos.emplace_back(i, j);
        }
    }

    pick(0, 0);

    cout << minCityCD << endl;

    return 0;
}
