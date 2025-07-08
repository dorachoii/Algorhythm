#include <bits/stdc++.h>
using namespace std;

const int n = 3;
int a[n][n], visited[n][n];

const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

void go(int y, int x){
    visited[y][x] = 1;
    cout << y << " : " << x << "\n";

    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        // 1. 오버플로우, 언더플로우 방지 - 가장 먼저 선행되어야 하는 조건!
        if(ny<0 || ny>=n || nx < 0 || nx >=n) continue; 
        // 이동할 수 있는 곳만 이동
        if(a[ny][nx]==0) continue;
        // 방문한 적 있다면 패스
        if(visited[ny][nx]) continue;
    }
}
 
int main(){
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    go(0,0);
}