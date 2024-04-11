#include <bits/stdc++.h>
using namespace std;

int r, c,visited[1501][1501];
char a[1501][1501];

int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};

// 1. 얼음 녹이기
vector<pair<int, int>> v;

void melt(int x, int y){
    visited[x][y] = 1;

    // 가장자리 v에 저장
    if(a[x][y] == 'X'){
        v.push_back({x,y});
        return;
    }

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx <0 || nx >= r || ny < 0 || ny >= c || visited[nx][ny]) continue;
        melt(nx, ny); 
    }
    return;
}

// 2. 백조끼리 연결
int Lvisited[1501][1501];

bool isConnected(int x, int y){
    Lvisited[x][y] = 1;

    for(int i = 0 ; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx <0 || nx >= r || ny < 0 || ny >= c || visited[nx][ny] || a[nx][ny] == 'X') continue;
        
        if(a[nx][ny] == 'L'){ return true;}

        if(a[nx][ny] == '.' && !Lvisited[nx][ny]){
            if(dfs(nx, ny))
            return true; //여기가 잘못됌
        } 
    }

    return false;
}

pair<int , int> lPos;

int cnt = 0;
int cnt2 = 0;

int main(){
    cin >> r >> c;

    for(int i = 0 ; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> a[i][j];

            //두번째꺼 저장되겠지.
            if(a[i][j] == 'L'){
                lPos.first = i;
                lPos.second =j;
            }
        }
    }

    while(true){
        memset(visited, 0, sizeof(visited));
        memset(Lvisited, 0, sizeof(Lvisited));
        v.clear();
        melt(0,0);

        cnt = v.size();

        for(pair<int, int> b : v){
            a[b.first][b.second] = '.';
        }

        bool flag = 0;

        if(isConnected(lPos.first, lPos.second)) flag = 1;
        cnt2++;
        if(!flag) break;
    }

    cout << cnt2;

    cout << "백조의 위치는 "<<lPos.first << "," << lPos.second <<'\n';
    cout << dfs(lPos.first, lPos.second);
}