#include <bits/stdc++.h>
using namespace std;

bool a[10][10];
int n;

int main(){

    a[1][2] = 1;
    a[1][3] = 1;
    a[3][4] = 1;

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(a[i][j]){
                cout << i << '\n';
                n = j;  // 다음 정점으로 갱신하는 방법과, 방문노드 체크위해 방문 배열을 따로 만드는 것이 옳을지 모르겠음
            }
        }
    }

}