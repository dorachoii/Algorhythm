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
//배추 좌표
int xx[max_k];
int yy[max_k];

//인접리스트
vector<int> adj[max_k];

//방문배열
bool visited[max_k];

//지렁이 마리수
int cnt;

//방문 체크 후 이동하는 함수
void go (int idx){
    //cout << "go 실행\n";
    visited[idx] = 1;

    //cout << "현재 노드는 " <<idx<<'\n';
    
    for(int there: adj[idx]){
        if(visited[there]) {
            //cout << there <<"은 방문한 적 있는 노드임\n";
            //끝 인덱스에서 너무 순회를 많이 하게 됌. 
            // idx 가 끝번미면 끝나야 함.
            //cnt--;  //여기가 잘못된 것 같음
            continue;
        }
        go(there);
        cnt--;
    }
}


int main(){
    
    cin >> T ; 

    for(int i = 0; i<T; i++){
        cin >> m >> n >> k;
        cnt = k;

        for (int i = 0; i < k; i++)
        {
            cin >> x >> y;
            // 배추밭 표시
            a[x][y] = 1;

            xx[i] = x;
            yy[i] = y;
        }

        // 배추의 x좌표가 서로 1차이 난다면 인접리스트 추가
        // 배추의 y좌표가 서로 1차이 난다면 인접리스트 추가
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                if ((abs(xx[i] - xx[j])) == 1 && yy[i] - yy[j] == 0)
                    adj[i].push_back(j);
            }
        }

        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                if ((abs(yy[i] - yy[j])) == 1 && xx[i] - xx[j] == 0)
                    adj[i].push_back(j);
            }
        }

        // 인접리스트 기반 방문 체크
        for (int i = 0; i < k; i++)
        {
            if (adj[i].size() && visited[i] == 0)
                go(i);
                //cnt--;
        }

        cout << cnt <<'\n';
    }
    
}

// 노력은 가상했으나, 각종 배열 초기화 안해주고 또쓰는 문제. 일단 테스트 케이스 2개는 통과한 코드임.