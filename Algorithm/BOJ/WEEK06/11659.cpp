// 1부터 구하는게 쉽다!

#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int a, b;

int sum[100004]; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        cin >> k;
        sum[i] = sum[i-1] + k;
    }

    for(int i = 0; i < m; i++){
        cin >> a >> b;
        cout << sum[b] - sum[a-1] << '\n';
    }
}

// scanf 는 안되나?