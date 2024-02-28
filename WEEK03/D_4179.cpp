// 일단 입력부터
#include <bits/stdc++.h>
using namespace std;
int a[1001][1001], n, m, visited[1001][1001];
char s;

pair<int, int> sPos;
pair<int, int> fPos;

// 지훈이도 움직이고 불도 움직임
//  왠지 불은 dfs로 움직여야 할 것 같고 (남는 위치없이 곳곳)
//  지훈이는 bfs로 최단으로 움직여야할 것 같은 기분인데..

// cnt 잘못해주고 있음.
// 지훈이는 bfs로 바꿔보기.

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int cnt = 0;

void dfs(int x, int y)
{
    visited[x][y] = 1;
    cout << "현재 지훈이의 위치는 " <<x <<',' << y << '\n';

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= n || x < 0 || ny >= m || y < 0)
        {
            cout << nx << ',' << ny << "가 가장자리에 닿았으므로 탈출 성공!" << '\n';
            cout << cnt;
            return;
        }

        if (a[nx][ny] == 0 && visited [nx][ny] == 0){
            cnt++;
            dfs(nx, ny);
            cout << cnt << "만큼 이동해왔음" << '\n';
        }            
    }

    cout << x << ',' << y << "에서 멈춰버렸다." << '\n';
    cout << "IMPOSSIBLE";
}

void Fdfs(int x, int y)
{
    visited[x][y] = 1;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= n || x < 0 || ny >= m || y < 0 || a[nx][ny] == 1) continue;

        if (visited[nx][ny] == 0)
            dfs(nx, ny);
    }
}

int main()
{

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> s;
            if (s == '#')
            {
                a[i][j] = 1;
            }
            else if (s == 'J')
            {
                sPos = {i, j};
                a[i][j] = 0;
            }
            else if (s == 'F')
            {
                fPos = {i, j};
                a[i][j] = 1;
            }
            else if (s == '.')
            {
                a[i][j] = 0;
            }
        }
    }

    // 탈출할 수 있는 공간 2로 표시하기 혹은 멈추기 필요.
    dfs(sPos.first, sPos.second);
    Fdfs(fPos.first, fPos.second);
}