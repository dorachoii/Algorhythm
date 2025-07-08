#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
char a[1004][1004]; // 나처럼 숫자 변환해서 익숙한 형태로 바꾸지 않고 그대로 사용함
int n, m, sx,sy, ret,y,x;

int dx[] = {-1,0,1,0};
int dy[] = {0,-1,-,1};

int fire_check[1004][1004];     // 불 위치 : 일종의 방문 배열
int person_check[1004][1004];   // 사람 위치 : 일종의 방문 배열

// custom operator
bool in(int a, int b){
    return 0 <=a && a < n && 0 <=b && b < m;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    queue<pair<int,int>> q;

    cin >> n >> m;

    // 초기값을 INF 즉, 가장 큰 값으로 해둔다.
    fill(&fire_check[0][0], &fire_check[0][0] + 1004 * 1004, INF);

    for(int i = 0; i < n; i++){
        for(int j = 0; j <m; j++){
            cin >> a[i][j];

            if(a[i][j] == 'F'){
                fire_check[i][j] = 1;
                q.push({i,j});
            }
            else if(a[i][j] = 'J'){
                sy = i;
                sx = j;
            }
        }
    }

    // 불의 최단 거리 표시 해두기.
    while(q.size()){
        tie(y,x) = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(!in(ny,nx)) continue;

            // 불이 INF 즉 초기값이 아니고 ( = 이동한 적이 있고), 벽이라면
            // 보통은 0 에서 1로 갱신해 주며 방문을 체크해주는 데, INF로 해둔 이유는
            // 불이 0개 일 수도 있기 때문, 그리고 가장 큰 케이스와 겹치지 않도록 INF
            if(fire_check[ny][nx] != INF || a[ny][nx] == '#') continue;

            // 이동 거리 누적
            fire_check[ny][nx] = fire_check[y][x] +1;
            q.push({ny,nx}); 
        }
    }


    person_check[sy][sx] = 1;
    q.push({sy,sx});

    // 사람 이동
    while(q.size()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        // 가장 자리에 닿으면 탈출!
        if(x == m-1 || y == n-1 || x == 0 || y == 0){
            ret = person_check[y][x];
            break;
        }

        for(int i = 0; i < 4 ; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            // 경계 체크를 따로 빼줌
            if(!in(ny,nx)) continue;
           
            if(person_check[ny][nx]|| a[ny][nx] == '#') continue;
            // 불이 사람을 앞지르면 탈출 불가
            if(fire_check[ny][nx] <= person_check[y][x]+1) continue;

            // 이동 거리 누적
            fir_check[ny][nx] = person_check[y][x] + 1;
            
            // bfs 진행
            q.push({ny,nx});
        }
    }

    if (ret != 0)
        cout << ret << "\n";
    else
        cout << "IMPOSSIBLE \n";
    return 0;
}