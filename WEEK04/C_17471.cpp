#include <bits/stdc++.h>
using namespace std;

int rNum, pNum[11], adjNum, cNum, a[11][11];
vector<vector<int>> adj;
vector<vector<int>> div;    // 선택된 것


int main(){

    cin >> rNum;

    for(int i = 0; i < rNum; i++){
        cin >> pNum[i];
    }

    for(int i = 0; i < rNum; i++){
        cin >> adjNum;

        vector<int> temp;
        for(int i = 0; i < adjNum; i++){
            cin >> cNum;
            temp.push_back(cNum);
        }
        adj.push_back(temp);
    }

    // 입력까지 완료
    // 이미 adj자체가 인접리스트인 상태

    // 1. 인접행렬 a로 만들기 - 완료
    for(int i = 0; i < rNum; i++){
        for(int b : adj[i]){
            a[i+1][b] = 1;
        }
    }

    // 2. 구역 나누기
    // 2-0.n개 중 몇개를 택하는 조합 중에 
    // 2-1.연결되어 있는지 체크하기.
    // 2-2.인구수 차이 비교하기.


    // 2-0.n개 중 몇개를 택하는 조합 중에 - 완료
    for(int i = 0; i < (1 << rNum); i++){
        vector<int> temp;
        
        for(int j = 0; j < rNum; j++){
            if(i & (1 << j)){
                temp.push_back(j)
            }
        }
        div.push_back(temp);
    }

    // 2-1.연결되어 있는지 체크하기.
    for(vector<int> k : div){
        for(int i = 0; i < k.length -1; i++){
            
            
        }
    }

}