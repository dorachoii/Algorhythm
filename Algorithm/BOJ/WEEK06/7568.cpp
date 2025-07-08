#include <bits/stdc++.h>
using namespace std;

int a[100], b[100];
int cnt;
int countBiggerthanMe(int idx);

int main(){
    cin >> cnt;

    for(int i = 0; i < cnt; i++){
        cin >> a[i] >> b[i];
    }

    for(int i = 0; i < cnt; i++){
        cout << countBiggerthanMe(i) << " ";
    }
}

int countBiggerthanMe(int idx){
    int bigCnt = 0;

    for(int k = 0 ; k < cnt; k++){
        if (k == idx) continue;
        if(a[idx] < a[k] && b[idx] < b[k]) bigCnt++;
    }
    
    return bigCnt+1;
}

