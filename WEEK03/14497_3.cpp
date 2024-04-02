#include <bits/stdc++.h>
using namespace std;

int n, m, a1,b1,a2,b2;
char a[303][303] ;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
int cnt = 0;

// void dfs(int x, int y){
//     //(3,4)
//     a[x][y] = '0';

//     for(int i = 0 ; i < 4; i++){
//         //(2,4) (4,4) (3,5) (3,3)

//         int nx = x + dx[i];
//         int ny = y + dy[i];

//         if(nx >= n || nx < 0 || ny >= m || ny < 0 ) continue;
//         if(a[nx][ny] == '#') break;
//         dfs(nx,ny);
//     }
//     cnt ++;
// }

void dfs(int x, int y) {
    a[x][y] = '0';

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= n || nx < 0 || ny >= m || ny < 0 || a[nx][ny] == '#')
            continue;  // Change from break to continue

        dfs(nx, ny);
    }
    cnt++;
}



int main(){
    // n: 5, m: 7
    cin >> n >> m >> a1 >> b1 >> a2 >> b2;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        } 
    }

    //(3,4)
    dfs(a1 -1, b1-1);

    cout << cnt;
}
