#include <bits/stdc++.h>
using namespace std;
int n, a[11][11], visited[11][11];
vector<pair<int, int>> co;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};


bool dfs(int x, int y){
    bool isAlive = true;

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny] == 1) {
            //cout <<"꽃을 심을 수 없습니다.\n";
            isAlive = false;
        }
    }

    if(isAlive){
        visited[x][y] = 1;

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            visited[nx][ny] = 1;
        } 
    }

    return isAlive;
}

int calculate(){
    int ret = 0;

    for(int i = 0; i < 11; i++){
        for(int j = 0; j < 11; j++){
            if(visited[i][j]) ret += a[i][j];
        }
    }

    return ret;
}

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            co.push_back({i,j});
        }
    }

    int mn = 20000000;

    for(int i = 0; i < co.size()-2; i++){
        for(int j = i + 1; j < co.size()-1; j++){
            for(int k = j + 1; k < co.size(); k++){

                //cout <<"꽃을 심었습니다\n";

                memset(visited, 0, sizeof(visited));

                if( dfs(co[i].first, co[i].second)&&
                dfs(co[j].first, co[j].second)&&
                dfs(co[k].first, co[k].second)){
                    mn = min(mn, calculate());
                }
            }
        }
    }

    cout<< mn;
}