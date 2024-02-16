#include <bits/stdc++.h>
using namespace std;

int n, m, a[9][9], nw[9][9], visited[9][9], wall;

vector<pair<int, int>> virusPlace;
vector<pair<int, int>> zeroPlace;
vector<pair<int, int>> selectedPlace;

vector<int> pollutedCnt;

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

int dfs(int y, int x)
{
    visited[y][x] = 1;

    int cnt = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (ny >= n || nx >= m || ny < 0 || nx < 0)
            continue;

        if (nw[ny][nx] == 0 && !visited[ny][nx])
        {
            cnt++;
            dfs(ny, nx);
        }
    }

    return cnt;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            nw[i][j] = a[i][j];

            if (a[i][j] == 0)
                zeroPlace.push_back({i, j});
            if (a[i][j] == 1)
                wall++;
            if (a[i][j] == 2)
                virusPlace.push_back({i, j});
        }
    }

    // 3개 뽑기
    for (int i = 0; i < zeroPlace.size() - 2; i++)
    {
        for (int j = i + 1; j < zeroPlace.size() - 1; j++)
        {
            for (int k = j + 1; k < zeroPlace.size(); k++)
            {

                nw[zeroPlace[i].first][zeroPlace[i].second] = 1;
                nw[zeroPlace[j].first][zeroPlace[j].second] = 1;
                nw[zeroPlace[k].first][zeroPlace[k].second] = 1;

                for (int h = 0; h < virusPlace.size(); h++)
                {
                    pollutedCnt.push_back(dfs(virusPlace[h].first, virusPlace[h].second));
                }

                memset(visited, false, sizeof(visited));
                nw[zeroPlace[i].first][zeroPlace[i].second] = 0;
                nw[zeroPlace[j].first][zeroPlace[j].second] = 0;
                nw[zeroPlace[k].first][zeroPlace[k].second] = 0;
            }
        }
    }

    sort(pollutedCnt.begin(), pollutedCnt.end());

    if (!pollutedCnt.empty())
        cout << n * m - pollutedCnt[0] - wall - 3;
    else
        cout << n * m - wall - 3;

    return 0;
}
