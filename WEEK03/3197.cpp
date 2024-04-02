#include <bits/stdc++.h>
using namespace std;

int r, c, visited[1501][1501];
char a[1501][1501];
vector<pair<int, int>> l;
vector<pair<int, int>> v;
pair<int, int> w;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

// 빙판의 좌표를 v에 저장하는 함수
// 가장자리만 체크하게됌 왜?
void melt(int x, int y){
    visited[x][y] = 1;

    //빙판이라면 좌표 저장
    if(a[x][y] == 'X'){
        v.push_back({x,y});
        // 물이 빙판 만나면 return하니까!
        return;
    }

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= r || ny < 0 || ny >= c || visited[nx][ny]) continue;
        melt(nx, ny);
    }
    return;
}

// 백조 연결되었니?

int visited2[1501][1501];

bool check(int x, int y, int xx, int yy){
    visited2[x][y] = 1;

    if(x == xx && y == yy) return true;

    for(int i = 0 ; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= r || ny < 0 || ny >= c || a[nx][ny] == 'X' || visited2[nx][ny]) continue;

        check(nx, ny, xx, yy);
    }

    return false;
}

int cnt = 0;
int cnt2 = 0;
int meltCnt = 0;
queue<int> q;

int main(){
    cin >> r >> c;

    for(int i = 0 ; i < r; i ++){
        for(int j = 0; j < c; j++){
            cin >> a[i][j];

            if(a[i][j] == '.' && cnt == 0){
                w.first = i;
                w.second = j;
                cnt++;
            }

            if(a[i][j] == 'L'){
                l.push_back({i,j});
            }
        }
    }

    while(true){
        // 방문배열, 빙판좌표 초기화
        cout <<"while문 반복!\n";

        memset(visited, 0, sizeof(visited));
        v.clear();

        melt(w.first,w.second);
        // 가장자리 1차로 녹임
        cnt2 = v.size();

        for(pair<int, int> b : v){
            a[b.first][b.second] = '.';
        }

        // 얼음이 하나도 안남으면 true체크하는 건데 그게 아니라, 
        // 백조가 갈 수 있으면 임.
        bool flag = 0;

        // 백조들의 위치가 connected component면 flag 1로 바꿔주기
        if(check(l[0].first, l[0].second, l[1].first, l[1].second)){
            cout <<"백조끼리 이어졌다!\n";
            flag = 1;
        }
    
        meltCnt++;
        //cout << "얼음을 " << meltCnt <<"번 녹였습니다.\n";

        if(!flag) break;
    }

    cout << meltCnt;
}

