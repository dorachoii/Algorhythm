#include <bits/stdc++.h>
using namespace std;
int n, m , a[101][101], edge[101][101], innerChzCnt;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

//가장 자리 파악하는 함수
void findEdge(int x, int y){
    for(int i = 0 ; i < height ; i ++){
        for(int j = 0; j < width; j++){
            if(a[i][j] == 1){
                for (int k = 0; k<4; k++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if(nx)
                }
            }
            
        }
    }
}

//치즈 녹이는 함수


int main(){

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < m ; j++){
            cin>> a[i][j];
        }
    }

}