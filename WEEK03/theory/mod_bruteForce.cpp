#include <bits/stdc++.h>
using namespace std;
int n,temp, ret;
vector<int> v;
const int mod = 11;
int cnt = 0;



void go(int idx, int sum){

    if(ret == 10) return;

    if(idx == n){       //재귀함수는 기저사례가 중요
        ret = max(ret, sum %mod);
            cnt++;
            return;
        
    }

    go(idx +1, sum + v[idx]);
    go(idx + 1, sum);
}


int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> temp;
        v.push_back(temp);
    }

    go(0,0);
    cout << ret << "\n";
    cout << cnt << "\n";
}