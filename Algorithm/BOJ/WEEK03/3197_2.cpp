#include <bits/stdc++.h>
using namespace std;

int r, c, Lvisited[1501][1501];
char a[1501][1501];
vector<pair<int, int>> l;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};

bool check(int x, int y){
    Lvisited[x][y] = 1;

    if(a[x][y] == 'L') return true;

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= r || ny < 0 || ny >= c || Lvisited[nx][ny] || a[nx][ny] == 'X') continue;

        if(a[nx][ny] == '.'){
            check(nx, ny);
        } 
    }

    return false;
}

int main(){
    cin >> r >> c;

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c ; j++){
            cin >> a[i][j];

            if(a[i][j] == 'L'){
                l.push_back({i,j});
            }
        }
    }

    a[l[0].first][l[0].second] = '.';

    cout << check(l[0].first, l[0].second);
}