#include <bits/stdc++.h>
using namespace std;

int r,c,k, visited[6][6], cnt, kcnt;
char a[6][6];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

void dfs(int x, int y){
    cout <<"현재 방문한 x,y는 " << x << "," << y <<'\n';
    visited[x][y] = 1;
    cnt++;
    cout <<"현재 시작점에서 이동한 거리는 "<< cnt<< '\n';
    if(cnt > k) return;

    if(x == 1 && y == c && cnt == k ){
        cout << cnt <<"번 만에 도착점에 도착\n";
        kcnt++;

        cnt= 0;
    memset(visited, 0, sizeof(visited));
        return;
    }

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx>r || nx<=0 || ny > c || ny <= 0|| a[nx][ny] == 'T') {
            cout << "오버플로우라 continue하겠다\n";
            continue;
        }

        if(!visited[nx][ny] || cnt<=k){
            dfs(nx,ny); 
            
        }   
    }        
}


int main(){
    cin >> r >> c >> k;

    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            cin >> a[i][j];
        }
    }

    
    
    dfs(r, 1);

    cout << kcnt;
}

