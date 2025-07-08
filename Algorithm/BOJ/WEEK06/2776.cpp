#include <bits/stdc++.h>
using namespace std;

int T, m, n, a, mid;
vector<int> note1;

int main(){
     ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> T >> m;

    while(T--){
    for(int i = 0; i < m; i++){
        cin >> a;
        note1.push_back(a);
    }

    //sort(note1.begin(), note1.end());

    //mid = note1[note1.size()/2];

    cin >> n;
    
    for(int i = 0; i < n; i++){
        int cnt = 0;
        cin >> a;

        for(int n: note1){
            if(n == a){
                cout << 1 << '\n';
                cnt++;
                break;
            }
        }
        if(cnt == 0){
            cout << 0 << '\n';
        }
    }
    }

    
}