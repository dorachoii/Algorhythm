#include <bits/stdc++.h>
using namespace std;

// 02. combination으로 푸는 방법
//  정상적 난쟁이 7명 뽑는 것과, 비정상적 난쟁이 2명 뽑는 것은 같음

int a[9], sum;
vector<int> v;
pair<int, int> ret; // pair자료 구조 쓴 것 나와의 차이

// 중첩 for문 생각하기
void solve(){
    for(int i = 0; i <9; i++){
        for(int j = 0; j < i; j++){
            ir(sum-a[i]-a[j] == 0){
                ret = {i,j};
                return;
            }
        }
    }
}

int main(){

    ios_base::sync_with_stdio;
    cin.tie(NULL); cout.tie(NULL);

    for(int i = 0; i < 9; i++){
        cin >> a[i]; sum += a[i];
    }
    solve();

    for(int i = 0; i < 9; i++){
        if(ret.first == i || ret.second == i) continue;
        v.push_back(a[i]);
    }

    sort(v.begin(), v.end());

    for(int i : v) cout << i << " ";
    return 0;

}
