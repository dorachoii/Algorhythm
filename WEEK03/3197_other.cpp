#include <bits/stdc++.h>
using namespace std;

const int max_n = 1501;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1}; 

int visited_swan[max_n][max_n], visited[max_n][max_n], R, C, day, swanY, swanX, y, x;
char a[max_n][max_n]; 

// waterQ : 물 좌표 입력 시 저장
// water_tempQ : 녹인 가장자리 저장
// swanQ : 백조 좌표 입력 시 저장
queue<pair<int, int>> waterQ, water_tempQ, swanQ, swan_tempQ;

string s;

// queue 초기화
void Qclear(queue<pair<int, int>> &q){
   queue<pair<int, int>> empty;
   // 빈 queue와 swap
   swap(q,empty);
}  

// 다른 방법:
// while(q.size())q.pop();

void water_melting(){

    // 물이 남아있으면 melt, 더 이상 물이 없으면 루프 종료
    while(waterQ.size()){
		tie(y, x) = waterQ.front();  
        // 제일 앞에 꺼 부터 꺼내기
        waterQ.pop();

        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= R || nx < 0 || nx >= C || visited[ny][nx])continue;

            // 얼음이라면 방문하고 temp에 넣고 녹이기.
            if(a[ny][nx] == 'X'){
                visited[ny][nx] = 1; 
                water_tempQ.push({ny, nx});
                a[ny][nx] = '.'; 
            } 
        }
    }
}

bool move_swan(){

    while(swanQ.size()){
		tie(y, x) = swanQ.front(); 
        swanQ.pop();


        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= R || nx < 0 || nx >= C || visited_swan[ny][nx])continue;
            visited_swan[ny][nx] = 1;

            // 이동할 수 있다면 swanQ에 넣기
            if(a[ny][nx] == '.')swanQ.push({ny, nx});
            // 이동할 수 없다면 tempQ에 넣기
            else if(a[ny][nx] == 'X') swan_tempQ.push({ny, nx});
            else if(a[ny][nx] == 'L') return true;
        }
    }
	return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> R >> C;
    for(int i = 0; i < R; i++){
        cin >> s;
        for(int j = 0; j < C; j++){
            a[i][j] = s[j];
            if(a[i][j] == 'L'){swanY = i; swanX = j;}
            if(a[i][j] == '.' || a[i][j] == 'L')visited[i][j] = 1, waterQ.push({i, j});
        }
    } 
    swanQ.push({swanY, swanX}); 


    visited_swan[swanY][swanX] = 1; 

    while(true){  
        // 백조가 이동할 수 있을 때까지 break;
        if(move_swan()) break;
        water_melting();

        // 가장 자리 넣기
        waterQ = water_tempQ;
        swanQ = swan_tempQ;

        Qclear(water_tempQ);
        Qclear(swan_tempQ);
        day++;
    }
    cout << day << "\n";
    return 0;
}
