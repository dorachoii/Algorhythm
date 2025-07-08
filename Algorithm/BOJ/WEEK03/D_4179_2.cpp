// 일단 입력부터

// 불이 여러 군데일 수 있다는 것 간과했고
// bfs자체는 끝까지 돌리는 거니까 하나씩 번갈아가며 짜는 것을 제대로 안했음

#include <bits/stdc++.h>
using namespace std;
int a[1004][1004], n, m, visited[1004][1004];
char s;

pair<int, int> sPos;
vector<pair<int, int>> fPos;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int cnt = 0;

void Fdfs(int x, int y)
{
    visited[x][y] = 1;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 여기 줄을 합쳐보고 싶음.
        // 근데 불도 최단보다 빨라야 경우의 수 중 가장 빠른 것들을 비교하는 게 맞으니까.
        if (nx >= n || nx < 0 || ny >= m || ny < 0 || a[nx][ny] == 1)
            continue;

        if (visited[nx][ny] == 0)
            //Fdfs(nx, ny);
    }
}

void Jbfs(int x, int y)
{
    visited[x][y] = 1;
    queue<pair<int,int>> q;

    q.push({x,y});

    while(q.size()){
        Fdfs(fPos.first, fPos.second);

        tie(x,y) = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m){
                //cout << "가장자리에 닿았다\n";
                cout << visited[x][y]+1<<'\n';
                return;
            }

            if(visited[nx][ny] && a[nx][ny]) continue;

            visited[nx][ny] = visited[y][x] +1;
            q.push({nx,ny});
        }
    }

    cout << "IMPOSSIBLE";
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

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
                fPos.push_back({i, j});
                a[i][j] = 1;
            }
            else if (s == '.')
            {
                a[i][j] = 0;
            }
        }
    }

    // 탈출할 수 있는 공간 2로 표시하기 혹은 멈추기 필요.
    // bfs가 끝나고 불이 시작되는게 아니라 동시에 둘이 함께 진행되어야 함.
    Jbfs(sPos.first, sPos.second);
}