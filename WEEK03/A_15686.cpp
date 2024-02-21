#include <bits/stdc++.h>
using namespace std;

int n, m, a[51][51],b[51][51], cityCD, CD,cnt;

vector<pair<int,int>> chickenV;
vector<pair<int,int>> homeV;

int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

int visited[51][51];

int chickenCnt;

// m개 이하로 고르면서 2를 체크하고 표시하는 거까지 구현
void go(int idx, bool bb){
    
    if (bb)
    {
        cout << idx << "번째 치킨집의 좌표를 선택했다\n";
        b[chickenV[idx].first][chickenV[idx].second] = 2;
        chickenCnt++;
    }

    if(idx == chickenV.size()-1 && chickenCnt <= m){
       // bfs 돌려야 되는데 일단 b 출력 // 표시하고 초기화
       cnt++;
       cout << "현재 " << cnt <<"번째 조합이고," << chickenCnt<<"개의 치킨집을 표시한 결과는 이러함\n";

       for(int i = 1; i <=n; i++){
        for(int j = 1; j <=n; j++){
            cout << b[i][j] <<" ";
        }
        cout <<'\n';
       }

       cout << "치킨집 리셋\n";
       for (int i = 1; i <= n; i++)
       {
           for (int j = 1; j <= n; j++)
           {
               if(b[i][j]==2) b[i][j]= 0;
           }
       }
       chickenCnt = 0;
       return;
    }
    
    go(idx+1, true);
    go(idx+1, false); 
}


int main(){
    cin>> n >> m;

    // a: 원본 배열 b : 집만 표시되어 있는 배열
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <=n; j++){
            cin>>a[i][j];
            b[i][j] = a[i][j];

            if(a[i][j]==1) homeV.push_back({i,j});
            if(a[i][j]==2) {
            b[i][j] = 0;    
            chickenV.push_back({i,j});}
            //b 복사 배열에는 집 표시만 해줌
        }
    }

    // 치킨 가게를 1 ~ m개로 세워가며 도시의 치킨 거리를 구할 것.

    if(chickenV.size() > m){
        //치킨 집을 m개 이하로 뽑아야 한다.
        go(0,1);
        
    }

}