#include <bits/stdc++.h>
using namespace std;

//dfs로 방향벡터 탐색
const int MAX = 101;
int n, a[MAX][MAX],b[MAX][MAX], minn = 2, maxx,k,maxCnt = 1;
bool visited[MAX][MAX];

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

void dfs(int x, int y){
    visited[x][y] = true;

    for(int i = 0; i <4; ++i){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >=0 && nx < n && ny >=0 && ny < n){
            if(b[nx][ny]&& !visited[nx][ny]){
                dfs(nx,ny);
            }
        }
    }
}

int main(){

    cin >> n;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> k;
            a[i][j] = k;

            if(k < minn){
                minn = k;
            }

            if(k > maxx){
                maxx = k;
            }
        }
    }

    for(int m = minn ; m < maxx; m++){

        memset(b,false, sizeof(b));
        memset(visited, false, sizeof(visited));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n;j++){
                if(a[i][j]>m) b[i][j] = 1;
            }
        }

        int cnt = 0;

        for(int i = 0; i<n;i++){
            for(int j = 0; j <n; j++){
                if(b[i][j] && !visited[i][j]){
                    dfs(i,j);
                    cnt++;
                }
            }
        }

        if(cnt > maxCnt){
            maxCnt = cnt;
        }
    }

    cout << maxCnt;

}