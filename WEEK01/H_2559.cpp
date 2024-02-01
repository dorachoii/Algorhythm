#include <bits/stdc++.h>
using namespace std;

int N,K;
//vector<int> sum;

int main(){

    cin >> N >> K;

    int a[N];
    
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }

    for(int i = 0; i < N-K+1; i++){
        int s = 0;
        for(int j = i; j < i+K; j++){
            
            s+= a[j];
            sum.push_back(s);
        }
    }

    sort(sum.begin(),sum.end());

    cout << sum[sum.size()-1];

}
//단순하게 풀었더니 메모리 초과
//정답률이 35%인데 너무 단순히 풀릴때부터 의심했어야 함.
//벡터를 쓴게 문제?