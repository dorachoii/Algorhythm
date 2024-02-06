#include <bits/stdc++.h>
using namespace std;

bool a[4][4] = {
    {0,1,1,1},
    {1,0,1,0},
    {1,1,0,0},
    {1,0,0,0},
};

const int V = 4;

bool aa[V][V] = {
    {0, 1, 1, 1},
    {1, 0, 1, 0},
    {1, 1, 0, 0},
    {1, 0, 0, 0},
};

int main()
{
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            if(a[i][j]){
                cout << i << "부터 " << j << "까지 경로가 있습니다.\n";

                //해당 정점으로부터 탐색하는 로직
                dfs(i);
                bfs(i);
            }
        }
    }
}