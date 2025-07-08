#include <bits/stdc++.h>
using namespace std;

int r,c,k, visited[6][6], cnt, kcnt;
char a[6][6];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

void dfs(int x, int y){

    visited[x][y] = 1;
    cnt++;

    if(x == 1 && y == c && cnt == k ){
        kcnt++;
        cnt = 0;
        return;
    }

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx>r || nx<=0 || ny > c || ny <= 0|| a[nx][ny] == 'T') continue;
        dfs(nx,ny);
    }
}


int main(){
    cin >> r >> c >> k;

    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            cin >> a[i][j];
        }
    }

    dfs(c, 1);
}