#include <bits/stdc++.h>
using namespace std;

int n, m, a[51][51], b[51][51], visited[51][51], CD, cityCD, minCityCD = 2500;

vector<pair<int, int>> cPos;
vector<pair<int, int>> hPos;

int cnt;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int bfs(int y, int x, int yy, int xx)
{
    // 방문배열 초기화
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            visited[i][j] = 0;
        }
    }

    int cnt = 0;
    int mn = 2500;
    queue<pair<int, int>> q;

    visited[y][x] = 1;
    q.push({y, x});

    while (q.size())
    {
        tie(y, x) = q.front();
        q.pop();

        // cout << "현재 탐색하는 정점은 " <<x <<","<<y <<'\n';
        // cout << "시작점에서 여기까지 " << visited[y][x] <<"만큼의 거리\n";

        if(y == yy && x == xx){
            return visited[y][x] -1;
        }

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 1 || ny >n || nx < 1 || nx >n || b[ny][nx] > 0)
                continue;

            if (visited[ny][nx])
                continue;

            visited[ny][nx] = visited[y][x] + 1;

            q.push({ny, nx});
        }
    }

    return -1;
}

// m 개 이하까지만  뽑아주기
void pick(int idx, bool bb)
{

    if (bb)
    {
        b[cPos[idx].first][cPos[idx].second] = 2;
    }
    else
    {
        b[cPos[idx].first][cPos[idx].second] = 0;
    }

    if (idx == cPos.size() - 1)
    {
        cnt++;
        int cCnt = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (b[i][j] == 2)
                    cCnt++;
            }
        }

        if (cCnt <= m)
        {
            cout << cnt << "번째 조합이 " << cCnt << "개의 치킨집으로 m보다 작아서 가능\n";
            // 선별된 것 마다, 도시의 치킨 거리 구할 것.
            cityCD = 0;
            

            for (int i = 0; i < hPos.size(); i++)
            {
                int minCD = 2500;
                cout << i << "번째 집에서 bfs를 실행합니다\n";
                for (int j = 0; j < cPos.size(); j++)
                {
                    CD  = bfs(hPos[i].first, hPos[i].second, cPos[j].first, cPos[j].second);
                    minCD = min(CD, minCD);
                }
                cityCD += minCD;
            }

            minCityCD = min(minCityCD, cityCD);
        }

        // cout << "치킨집 리셋\n";
        b[cPos[idx].first][cPos[idx].second] = 0;

        return;
    }

    pick(idx + 1, true);
    pick(idx + 1, false);
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            b[i][j] = a[i][j];

            if (a[i][j] == 1)
                hPos.push_back({i, j});
            if (a[i][j] == 2)
            {
                cPos.push_back({i, j});
                b[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < cPos.size(); i++)
    {
        pick(i, true);

        // cout << "치킨집 리셋\n";

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (b[i][j] == 2)
                    b[i][j] = 0;
            }
        }
    }

    cout << minCityCD;
}