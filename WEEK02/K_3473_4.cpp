#include <bits/stdc++.h>
using namespace std;
// 시간초과

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;

    int fiveCnt = 0;

    for(int i = 0; i < n; i++){
        int k;
        cin >> k;

        for(int j = 5; j <=k; j*=5){
            fiveCnt += k/j;
        }

        cout << fiveCnt <<'\n';
    }
}