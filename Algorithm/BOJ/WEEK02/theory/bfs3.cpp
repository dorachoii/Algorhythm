#include <bits/stdc++.h>
using namespace std;

const int max_n = 104;
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

int n, m, a[max_n][max_n], visited[max_n][max_n], y,x,sy,sx,ey,ex;

int main(){
    scanf("%d %d", &n,&m);
    cin >> sy >> sx;
    cin >> ey >> ex;

    for(int i = 0; i <n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    queue<pair<int, int>> q;

    visited[sy][sx] = 1;
    q.push({sy,sx});

    while(q.size()){
        tie(y,x) = q.front(); q.pop();  //여러 변수를 묶어서 하나의 변수로 사용

        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny <0 || ny >=n || nx < 0 || nx>=m || a[ny][nx]== 0) continue;

            if(visited[ny][nx]) continue;

            visited[ny][nx] = visited[y][x] +1;
            q.push({ny,nx});
        }
    }
}