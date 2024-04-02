#include <stdio.h>
#include<algorithm>
#include<queue>
using namespace std; 

// 0을 만나면 계속 탐색, 1 만나면 멈추기
// 기존의 bfs에 queue를 두 개 사용

char a[301][301];
int n, m, x1, y1, x2, y2; 
typedef pair<int, int> pii;

int visited[301][301];
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int ret; 
queue<int> q;

int main(){
    scanf("%d %d", &n, &m);
    scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
    y1--, x1--, y2--, x2--; 

    for(int i = 0; i < n; i++){
        scanf("%s", a[i]); 
    }  

    //2차원 좌표 하나로 받는 법
    q.push(1000 * y1 + x1);
    visited[y1][x1] = 1; 
    int cnt = 0; 

    // '1'과 '#'를 구분해주지 않아도 되는 이유는?
    // 여기서 #을 거르기 때문?
    
    while(a[y2][x2] != '0'){ 

        cnt++;
        queue<int> temp; 

        while(q.size()){
            int y = q.front() / 1000; 
            int x = q.front() % 1000;  

            q.pop();  

            for(int i = 0; i < 4; i++){
                int ny = y + dy[i]; 
                int nx = x + dx[i];
                if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue; 

                visited[ny][nx] = cnt;  

                if(a[ny][nx] != '0'){
                    a[ny][nx] = '0'; 
                    temp.push(1000 * ny + nx);

                    // 1 만나기 전 0들은 temp에 넣고
                    // 1 만나면 q에 넣고
                }
                else q.push(1000 * ny + nx); 
            }
        }

        q = temp;  

        
    }

    printf("%d\n", visited[y2][x2]); 
}