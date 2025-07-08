#include <bits/stdc++.h>
using namespace std;

int n, a[101][101], minn = 2, maxx,k,ret, maxRet,cnt;
bool b[101][101];

int visited[101][101];

const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

void go(int y,int x){
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny <0 || ny >=n || nx <0 || nx >= n) continue;
        if(b[ny][nx] == 1) continue;
        if(visited[ny][nx]) continue;
        go(ny,nx);
    }
    ret++;
    return;
}

int main(){

    cin >> n;
    cnt = n *n;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> k;
            a[i][j] = k;
            
            if(k < minn) {
                minn = k;
            }

            if(k > maxx){
                maxx = k;
            }
        }
    }
    cout << "min은 " << minn << ", max는 " << maxx <<'\n';

    //수위 하나씩 늘려가며 안전영역 몇개인지 셀 것
    //true 잠겼다
    for(int m = 1 ; m <101; m++){
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(b[i][j] <= m) b[i][j] = true;
            }
        }

        //연결요소 개수 구하기
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                go(i,j);
            }
        }        

        if(ret > maxRet){
            maxRet = ret;
        }

        

        ret = 0;
    }

    cout << maxRet;
    
}
