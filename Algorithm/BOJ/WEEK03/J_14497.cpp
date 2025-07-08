#include <bits/stdc++.h>
using namespace std;
#define y1 aaa

//dfs
int n, m , x1,y1, x2,y2;
char a[301][301];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int cnt = 0;

void dfs(int x, int y){

    cout << "현재 x, y는" << x << "," << y<<'\n';

    if(a[x][y] == '#') {
        cout << "#을 만나서 종료" << '\n';
        return;
    }

    a[x][y] = '0';
    cnt++;

    int nx, ny = 0;

    for(int i = 0; i < 4; i++){
        nx = x + dx[i];
        ny = y + dy[i];

        if(nx > n || nx <=0 || ny>m || ny<=0 ) continue;
        dfs(nx, ny);        
    }
}

int main(){
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            //cout << a[i][j];
        }
        //cout << '\n';
    }

    dfs(x1,y1);
    cout << cnt;

}