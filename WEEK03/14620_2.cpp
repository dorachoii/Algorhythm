#include <bits/stdc++.h>
using namespace std;

int n, price[11][11], garden[11][11];
vector<pair<int, int>> co;
vector<pair<int, int>> leaf;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};

bool blossom(int x, int y){
    bool isDead = false;
    garden[x][y] = 1;
    
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        leaf.push_back({nx, ny});

        if(nx >=0 || nx < n || ny < 0 || ny >= n || garden[nx][ny]) {
            isDead = true;
        }        
    }

    // 네 잎이 모두 가능할 때만!
    if(!isDead){
        for(int i = 0; i < 4; i++){
            garden[leaf[i].first][leaf[i].second] = 1;
        }
    }
    return isDead;
}

int calculate(){
    int ret = 0;

    for(int i = 0; i < 11; i++ ){
        for(int j = 0; j < 11; j++){
            if(garden[i][j]){
                ret += price[i][j];
            }
        }
    }
    return ret;
}

int main(){

    //화단 너비 : n
    cin >> n;

    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n; j++){
            cin >> price[i][j];
            co.push_back({i,j});
        }
    }

    int mn = 2000000;

    //3개 spot고르기
    for(int i = 0; i < co.size()-2; i++){
        for(int j = i +1; j < co.size()-2; j++){
            for(int k = j + 1; k < co.size(); k++){
                if(blossom(co[i].first, co[i].second)&&
                blossom(co[j].first, co[j].second)&&
                blossom(co[k].first, co[k].second)){
                    mn = min(mn, calculate());
                }

                memset(garden, 0, sizeof(garden));
            }
        }
    }

    cout << mn;
}