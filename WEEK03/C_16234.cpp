#include <bits/stdc++.h>
using namespace std;

int n, l,r, ppl, a[51][51];
bool visited[2501];

map<pair<int,int>, int> node;

vector<vector<int>> adj;


int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

void connect(int x, int y){
    visited[node[{x,y}]] = 1;

    for(int i = 0; i < 4; i++){
        
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx<0 || nx>=n || ny < 0 || ny>=n) continue;

        // 2차원 좌표를 1개의 노드로 묶는 방법
        if (abs(a[nx][ny] - a[x][y]) >= l && abs(a[nx][ny] - a[x][y]) <= r){
            adj[node[{x,y}]].push_back({node[{nx,ny}]});
        }
    }
}

void uniteSUM(int x, int y){
    //현재 좌표로 부터 이어진 연합의 sum 구하기

    for(int i = 0; i < adj[node[{x,y}]]; i++){
        
    }

}




int main(){
    cin >> n >> l >> r;

    int idx = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            
            //2차원 좌표에 인덱스 매김
            // 0 1
            // 2 3
            node[{i,j}] = idx;
            idx++;
        }
    }

    // 조건에 따라 열렸는지 체크하고 인접리스트 표기
   

}