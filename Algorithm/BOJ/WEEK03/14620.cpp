#include <bits/stdc++.h>
using namespace std;

// 3지점을 정하고 모두 피게 하면서 가장 싼 가격에 화단 대여
// 겹치면 죽음

int n, a[11][11], f[11][11];

// 3개의 점 뽑는 경우의 수
vector<pair<int, int>> co;

//dfs 구현, min 갱신
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};

int dfs(int x, int y){
    int ret = 0;
    f[x][y] = 1;
    bool isDead = false;

    cout << "꽃을 심었습니다\n";
    
    for(int i = 0; i < 4; i++){
        if(!isDead){
            int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >=n || ny < 0 || ny >= n ||f[nx][ny]) {
            cout << "꽃잎을 펼칠 수 없어 죽었습니다\n";
            //f[x][y] = 0;
            isDead = true;
            return 2000000;
            //
        }
        cout << "꽃잎을 펼쳤습니다.\n";
        f[nx][ny] = 1;
        }    
    }


        for(int i = 0; i < 11; i++){
        for(int j = 0; j < 11; j++){
            if(f[i][j]) ret+= a[i][j];
        }
    
    cout << "꽃잎이 펼쳐진 곳의 땅값은 " << ret;
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
    cout << co.size();

    int minn = 200000;

    for(int i = 0; i < co.size()-2; i++){
        for(int j = i+1; j < co.size()-1; j++){
            for(int k = j+1; k < co.size(); k++){


                

                minn = min(minn, dfs(co[i].first, co[i].second) +
                dfs(co[j].first, co[j].second) + 
                dfs(co[k].first, co[k].second));

                memset(f, 0, sizeof(f));

                if(minn == 22){
                     cout << "현재 채택된 좌표는 " << co[i].first << "," << co[i].second <<"랑"
                 << co[j].first <<","<< co[j].second << "랑" << co[k].first << "," << co[k].second <<'\n';
                }
                
            }
        }
    }

    cout << minn;
    
}

