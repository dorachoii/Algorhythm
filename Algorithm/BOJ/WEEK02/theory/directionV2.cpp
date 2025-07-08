//Q.3 * 3맵을 입력받아야 한다.
// 이 맵은 1, 0으로 이루어져있고{0, 0} 은 무조건 1임을 보장한다.
//{0, 0} 부터 4방향 기준으로 한칸씩 탐색해나가며 
//방문한 정점은 다시 방문하지 않으며 방문하는 좌표를 출력하는 코드를 구현하시오.

#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0,1,0};
const int dx[] = {0,1,0,-1};

bool visited[9];
int idx;

int main(){

//  visited 배열의 정점과 좌표를 어떻게 매핑하지? 2차원적 요소와 1차원적 요소
    for(int x = 0 ; x < 3; x++){
        for(int y = 0 ; y < 3; y++){
            idx++;
            for(int i = 0; i < 4; i++){

                if(visited[idx]) continue;

                int ny = y + dy[i];
                int nx = x + dx[i];
                visited[idx] = true;
            }           
        }
        
    }
}