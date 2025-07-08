#include <bits/stdc++.h>
using namespace std;

int n, m, a[51][51], visited[51][51];
string s;

vector<pair<int, int>> LPos;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int bfs(int sx,int sy, int ex, int ey){
    queue<pair<int,int>>q;

    visited[sx][sy] = 1;
    if(sx == ex && sy == ey) return visited[sx][sy];
    q.push({sy,sx});

    while(q.size()){
        tie(sx,sy) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = sx + dx[i];
            int ny = sy + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || a[nx][ny] == 0)
                continue;

            visited[nx][ny] = visited[sx][sy] + 1;
            q.push({nx,ny});
        }
    }

    return -1;

}

int main(){

    cin >> n >> m >> s;

    cout << "a에 들어간 배열은\n";
    
    for (char a : s)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
            
                if(a == 'W') a[i][j] = 0;
                if(a == 'L'){
                    a[i][j] = 1;
                    LPos.push_back({i,j});
                }
            }
            cout << a[i][j] <<" ";
        }
        cout <<'\n';
    }

    int mxd = -1;

    for(int i = 0; i < LPos.size()-1; i++){
        for(int j = i; j < LPos.size(); j++){
        
            int k = bfs(LPos[i].first, LPos[i].second, LPos[j].first, LPos[j].second);
            mxd = max(mxd, k);
        }
    }

    cout << mxd;

}