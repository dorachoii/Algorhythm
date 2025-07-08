#include <bits/stdc++.h>
using namespace std;

int n,k,temp,psum[100001],ret = -100000004; // 넉넉하게 설정

// 최대값을 구하라 >> 최솟값부터 최댓값을 갱신해나가는 것
// 최솟값을 구하라>> 최댓값부터 최솟값을 



int main(){
    cin >> n >> k;

    for(int i = 1; i <= n; i++){
        cin>> temp;
        psum[i] = psum[i-1] +temp; 
    }

    for(int i = k; i <=n; i++){
        ret = max(ret,psum[i] - [sum[i-k]]);// 최댓값은 최소를 정해두고 갱신하는 형식으로 구한다는 것
                                            // 나는 다 넣고 정렬 후 마지막 원소 뽑음
    }

    cout << ret <<'\n';
    return 0;
}