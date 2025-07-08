#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin>>N;
    int l=1, r=2; // [l,r)
    int sum = 1;
    int cnt=0;

    while(r<=N+1){
        if(sum==N){
            cnt++;
            sum=sum - l++ + r++;
        }
        else if(sum<N){
            sum+=r++;
        }
        else{
            sum-=l++;
        }
    }
    cout << cnt << '\n';
}

// 절반 이상부터는 안해도될듯!
// 갯수가 같은건 하나밖에 없을듯!