#include <bits/stdc++.h>
using namespace std;

const int max_m = 101;
int m, n, k, paper[max_m][max_m], cnt, x, y;
int a, b, c, d;

bool visited[max_m][max_m];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
vector<int> spce;

int dfs(int x, int y)
{
    int spc = 0;
    visited[x][y] = 1;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
        if (!paper[nx][ny] && !visited[nx][ny]){
            dfs(nx, ny);
            spc++;
        }        
    }
    return spc;
}

int main()
{

    cin >> m >> n >> k;

    // 종이 채우기
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> a >> b >> c >> d;

            for (int x = a; x < c; x++)
            {
                for (int y = b; y < d; y++)
                {
                    paper[x][y] = 1;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int k = dfs(i, j);

            if(k >0){
                spce.push_back(k);
                cnt++;
            }            
        }
    }

    cout << cnt <<'\n';
    for(int a : spce) cout << a << " ";
}