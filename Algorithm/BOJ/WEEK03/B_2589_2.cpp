// 일단 입력받아 표시하기
// 두 군데 뽑기 
// 최단거리 구하기 , max 갱신하기

#include <bits/stdc++.h>
using namespace std;

int n, m, a[51][51], visited[51][51];
string s;

vector<pair<int, int>> LPos;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int bfs(int sx, int sy, int ex, int ey){

    queue<pair<int, int>> q;

    visited[sx][sy] = 1;
    q.push({sx,sy});

    while(q.size()){
        tie(sx,sy) = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = sx + dx[i];
            int ny = sy + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m || a[nx][ny] == 0) continue;
            if(visited[nx][ny]) continue;

            if (sx == ex && sy == ey)
            {
                return visited[sx][sy];
            }

            visited[nx][ny] = visited[sx][sy] + 1;
            q.push({nx, ny});
        }
    }

    return -1;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m ;

    for(int i = 0; i < n; i++){
        cin >> s;

        for(int j = 0; j < m; j++){
            if(s[0] == 'W') a[i][j] = 0;
            if(s[0] == 'L') {
                a[i][j] = 1;
                LPos.push_back({i,j});
            }
            s.erase(0,1);           
        }
    }

    int mxd = 0;

    for(int i = 0; i < LPos.size()-1; i++){
        for(int j = i ; j < LPos.size(); j++){

            memset(visited, false, sizeof(visited));


            //cout << "시작 좌표는 (" << LPos[i].first << "," << LPos[i].second <<") 이고 종착 좌표는 (" <<   LPos[j].first << "," << LPos[j].second <<")\n";
            int k = bfs(LPos[i].first, LPos[i].second, LPos[j].first, LPos[j].second);
            mxd = max(k, mxd);
        }
    }

    cout << mxd;

}