#include <bits/stdc++.h>
using namespace std;

int r, c, visited[21][21];
char a[21][21];

string str;

bool isNew (char c){

    for(char s: str){
        if(s == c) {
            return false;}
        
    }

    return true;
}

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int mx = 0;

int bfs(int x, int y){
    memset(visited, 0, sizeof(visited));
    cout << "visited 배열을 초기화했습니다\n";

    visited[x][y] = 1;
    str += a[x][y];
    cout << "현재 str은 " << str << '\n';

    queue<pair<int, int>> q;
    q.push({x,y});

    while(q.size()){
        cout <<"현재 queue의 사이즈는 " << q.size()<<'\n';

        tie(x,y) = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= r || ny < 0 || ny >= c || visited[nx][ny] ) continue;       
            if(!isNew(a[nx][ny])) break;

            visited[nx][ny] = visited[x][y] + 1;
            q.push({nx, ny});

            mx = max(mx, visited[nx][ny]);
        }
    }

    return mx;
}


int main(){
    cin >> r >> c;

    for(int i = 0; i < r ; i++){
        for(int j = 0; j < c; j++){
            cin >> a[i][j];
        }
    }

    int mxmx = 0;

    for(int i = 0; i < c; i++){
        mxmx = max(bfs(0,i), mxmx);
    }

    cout << mxmx;
    
}