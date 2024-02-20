// n,m : [3,8]

#include <bits/stdc++.h>
using namespace std;

// a: 원본 배열 , b: 바꿀 배열, 마지막에 0이 몇 개인지 체크
// 5중 For문이 괜찮으려나..

int n, m, a[9][9], b[9][9], safeSize, zeroCnt;

vector<pair<int, int>> zeroPlace;
vector<pair<int, int>> virusPlace;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void polluteDFS(int x, int y)
{

    b[x][y] = 3;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m || b[nx][ny] > 0)
            continue;
        polluteDFS(nx, ny);
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            b[i][j] = a[i][j];

            if (a[i][j] == 0)
            {
                zeroPlace.push_back({i, j});
            }
            else if (a[i][j] == 2)
            {
                virusPlace.push_back({i, j});
            }
        }
    }

    // 벽 세울 곳 3개 뽑기
    for (int i = 0; i < zeroPlace.size() - 2; i++)
    {
        for (int j = i + 1; j < zeroPlace.size() - 1; j++)
        {
            for (int k = j + 1; k < zeroPlace.size(); k++)
            {

                // cout <<"원래 필드는 "<<'\n';

                zeroCnt = 0;
                // b를 a로 초기화하는 것 필요.
                for (int v = 0; v < n; v++)
                {
                    for (int x = 0; x < m; x++)
                    {
                        b[v][x] = a[v][x];
                        // cout << b[v][x] <<" ";
                    }
                    // cout << '\n';
                }

                // 세군대 벽을 세웠어요.
                b[zeroPlace[i].first][zeroPlace[i].second] = 1;
                b[zeroPlace[j].first][zeroPlace[j].second] = 1;
                b[zeroPlace[k].first][zeroPlace[k].second] = 1;

                // cout << "벽을 세울 좌표는 (" << zeroPlace[i].first << "," << zeroPlace[i].second << ")"
                //  << "(" << zeroPlace[j].first <<", " <<zeroPlace[j].second <<") "
                //  << "(" << zeroPlace[k].first <<", " <<zeroPlace[k].second <<") \n";

                // 바이러스가 오염을 시킬 겁니다.
                for (int v = 0; v < virusPlace.size(); v++)
                {
                    polluteDFS(virusPlace[v].first, virusPlace[v].second);
                }

                // cout << "오염 후 필드는 " <<'\n';

                // 안전 영역 0을 카운트해줄게요.

                for (int v = 0; v < n; v++)
                {
                    for (int x = 0; x < m; x++)
                    {

                        // cout << b[v][x] <<" ";
                        if (b[v][x] == 0)
                            zeroCnt++;
                    }
                    // cout <<'\n';
                }
                // cout <<'\n';

                safeSize = max(safeSize, zeroCnt);
            }
        }
    }

    cout << safeSize;
}