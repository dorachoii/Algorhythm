#include <bits/stdc++.h>
using namespace std;
#define y1 aaa

int n,m,x1,x2,y1,y2;
char a[303][303];
 
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
int cnt = 0;

void dfs(int x, int y){
    a[x][y] = '0';
    cnt++;

    if(a[x][y] == '#') return;

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >=n || ny < 0 || ny >= m || a[nx][ny] == '1') continue;

        dfs(nx, ny);
    }

    
}

int main(){
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;

    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    dfs(x1, y1);

    cout << cnt;
}