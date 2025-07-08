#include <bits/stdc++.h>
using namespace std;

int h, n, k;
vector<int> node;
int middleIdx;
vector<vector<int>> level;

// 반대로 생각하면 
// 인접행렬로 그어두고 이것을? 

void checkHeight(){
    k = node.size();
    
    middleIdx = k/2;
    
    for(int i = 0; i < middleIdx ; i++){
        
    }

}


int main(){

    cin >> h;
     
    int two = 1;

    for(int i = 1; i < h; i++ ){
        two *= 2;
        sum += two;
    }

    node.push_back(0);

    for(int i = 0; i < sum; i++){
        cin >> n;
        node.push_back(n);
    }






}