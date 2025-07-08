#include <bits/stdc++.h>
using namespace std;

int r, c, visited[21][21];
char a[21][21];



int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int mx = 0;

int bfs(int x, int y) {
    string str = "";
    memset(visited, 0, sizeof(visited));

    // 정점 방문 표시
    visited[x][y] = 1;

    queue<pair<int, int>> q;
    // 현재 점 queue에 push
    q.push({x,y});

    // queue가 빌 때까지 반복. 즉, 방문할 정점이 없을 때 까지 반복
    while(q.size()){
        // 가장 앞에 있는 요소 빼서 넣어줌
        str += a[q.front().first][q.front().second];
        cout <<"현재 str은 " << str <<'\n';

        tie(x,y) = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            cout <<"현재 탐색하려는 글자는 " << a[nx][ny] <<'\n';

            if(nx < 0 || nx >= r || ny < 0 || ny >= c || visited[nx][ny]) {
                cout <<"오버플로우라 넘김\n";
                continue;}
            if(str.find(a[nx][ny]) != string::npos) {

                cout << a[nx][ny]<<" 는 전에 들어온 글자라 넘김\n";
                continue;
            }
        
            cout <<"조건 만족해서 넣겠다!   \n";

            visited[nx][ny] = visited[x][y] + 1;
            q.push({nx, ny});
            mx = max(mx, visited[nx][ny]);
        }

    }
    return mx;
}

int main(){

    cin >> r >> c;

    for(int i = 0 ; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> a[i][j];
        }
    }

    cout << bfs(0, 0);

}