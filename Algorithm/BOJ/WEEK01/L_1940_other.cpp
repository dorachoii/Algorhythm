#include <bits/stdc++.h>
using namespace std;

int n,m;
int cnt;
int a[15001];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;

    for(int i = 0; i < n; i++) cin >> a[i];

    if(m > 200000) cout << 0 << '\n';   // 여기 왜?
    // 3개 까지는 중첩 for문!
    // 시간초과가 타이트한 경우 이런 식으로 안되면 그냥 바로 걸러야 함.
    // 시간 초 늘릴 수 있음
    else{
        for(int i = 0; i < n; i++){
            for(int j = i+1; j<n; j++){
                if(a[i] + a[j] == m) cnt++;
            }
        }

        cout << cnt<< '\n';
    }


}