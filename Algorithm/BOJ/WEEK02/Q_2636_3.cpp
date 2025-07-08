#include <bits/stdc++.h>
using namespace std;

int n, m, a[101][101], visited[101][101];
vector<pair<int, int>> startCO;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int x, int y)
{

    visited[x][y] = 1;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;

        if (a[nx][ny] && !visited[nx][ny])
        {
            dfs(nx, ny);
        }
    }
}

// 아래, 아래왼대각선, 아래오른대각선
// 오른쪽, 오른위대각선, 오른아래대각선
// 위, 위왼대각선, 위오른대각선
// 왼, 왼위대각선, 왼아래 대각선

// 각 꼭짓점에 도달했다를 어떻게 break 걸어줄지가 문제

int di[] = {1, 1, 1, 0, -1, 1, -1, -1, -1, 0, -1, 1};
int dj[] = {0, -1, 1, 1, 1, 1, 0, -1, 1, -1, -1, -1};

bool isDownDone, isRightDone, isUpDone, isLeftDone;

void meltingEdge(int x, int y)
{

    a[x][y] = 0;

    if (!isDownDone)
    {
        for (int i = 0; i < 3; i++)
        {
            int ni = x + di[i];
            int nj = y + dj[i];

            if (ni < 0 || ni >= n || nj < 0 || nj >= m)
                continue;

            if (a[ni][nj])
            {
                meltingEdge(ni, nj);
                cout << "아래로 이동" << '\n';
            }
            else
            {
                isDownDone = true;
                cout << "아래 이동이 끝이 났습니다" << '\n';
            }
        }
    }

    if (!isRightDone)
    {
        for (int i = 3; i < 6; i++)
        {
            int ni = x + di[i];
            int nj = y + dj[i];

            if (ni < 0 || ni >= n || nj < 0 || nj >= m)
                continue;

            if (a[ni][nj])
            {
                meltingEdge(ni, nj);
                cout << "오른쪽으로 이동" << '\n';
            }
            else
            {
                isRightDone = true;
                cout << "오른쪽으로 이동이 끝이 났습니다" << '\n';
            }
        }
    }

    if (!isUpDone)
    {
        for (int i = 6; i < 9; i++)
        {
            int ni = x + di[i];
            int nj = y + dj[i];

            if (ni < 0 || ni >= n || nj < 0 || nj >= m)
                continue;

            if (a[ni][nj])
            {
                meltingEdge(ni, nj);
                cout << "위쪽으로 이동" << '\n';
            }
            else
            {
                isUpDone = true;
                cout << "위쪽으로 이동이 끝이 났습니다" << '\n';
            }
        }
    }

    if (!isLeftDone)
    {
        for (int i = 9; i < 12; i++)
        {
            int ni = x + di[i];
            int nj = y + dj[i];

            if (ni < 0 || ni >= n || nj < 0 || nj >= m)
                continue;

            if (a[ni][nj])
            {
                meltingEdge(ni, nj);
                cout << "왼쪽으로 이동" << '\n';
            }
            else
            {
                isLeftDone = true;
                cout << "왼쪽으로 이동이 끝이 났습니다" << '\n';
            }
        }
    }
}

int findPiece(int n, int m)
{
    // 1.connected component 개수와 각 시작 지점 파악.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] && !visited[i][j])
            {
                dfs(i, j);
                startCO.push_back({i, j});
            }
        }
    }

    int cheezeCnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j])
                cheezeCnt++;
        }
    }

    return cheezeCnt;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    // 1,2를 좌표상 1이 하나도 없을 때까지 반복
    // 3. 현재 치즈가 남아있는지 체크

    int minCheeze = 10000;
    int meltingTime = 0;
    int leftCheeze;

    // 1. connectedComponent
    do
    {
        leftCheeze = findPiece(n, m);

        // 2.가장 자리 녹여 가기.
        for (int i = 0; i < startCO.size(); i++)
        {
            isDownDone = false;
            isRightDone = false;
            isUpDone = false;
            isLeftDone = false;
            meltingEdge(startCO[i].first, startCO[i].second);
        }

        startCO.clear();
        meltingTime++;
        minCheeze = min(minCheeze, leftCheeze);

        cout << "아직 치즈가 남아있어서 melting을 실행했고 melt 횟수는 " << meltingTime << '\n';
        cout << "현재 남은 치즈는 " << leftCheeze << '\n';
    } while (leftCheeze > 0);

    cout << meltingTime << '\n';
    cout << minCheeze << '\n';
}
