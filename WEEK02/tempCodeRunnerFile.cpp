//공간 충분히 마련해두고 주어진 공간만큼만 접근한다
//필요한 공간만 마련하여, 접근 시 오류를 줄인다. hmm

#include <bits/stdc++.h>
using namespace std;
int T, m,n,k,x,y;

const int max_m = 52;
const int max_n = 52;
const int max_k = 2501;

//배추밭 표시 2차원 배열, 인접행렬, 방문배열 , 지렁이 마리수 공간 필요

//배추밭 표시 2차원 배열
bool a[max_m][max_n];

//배추 좌표 저장 배열
int xx[max_k];
int yy[max_k];

//인접행렬
bool b[max_m][max_n];

//방문배열
bool visited[max_k];

//지렁이 마리수
int cnt;

//방문 체크 후 이동하는 함수
void go (int from){
    cnt++;
    visited[from] = 1;
    
    for(int i  = 0; i < k; i++){
        if(visited[i]) continue;
        if(b[from][i]) go(i);
    }
}


int main(){

    cin >> T >> m >> n >> k;

    for(int i = 0; i < k; i++){
        cin >> x >> y;
        //배추밭 표시
        a[x][y] = 1;
        xx[i] = x;
        yy[i] = y;
    }

    // 배추밭 인접행렬 표시 - 점 간의 x좌표 차이가 1이거나 y좌표 차이가 1, 모두는 불가.
    for(int i = 0; i < xx.size()-1; i++){
        for(int j = i+1; j< xx.size(); j++){
            if(abs(xx[i] - xx[j]) == 1) {
                b[i][j] = 1;
                continue;
            }           
        }
    }

    for(int i = 0; i < yy.size()-1; i++){
        for(int j = i+!; j < yy.size(); j++){
            if(abs(yy[i]-yy[j])==1){
                b[i][j] = 1;
                continue;
            }
        }
    }

    //방문배열 표시 및 이동

    for(int i = 0; i < k; i++){
        for(int j = 0; j < k; j++){
            if(b[i][j] && visited[i]==0){
                go(i);
            }
        }
    }

    cout << cnt;


}