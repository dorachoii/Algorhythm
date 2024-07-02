#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--) {
        int N, M;
        cin >> N;

        unordered_set<int> note1;
        for(int i = 0; i < N; i++){
            int a;
            cin >> a;
            note1.insert(a);
        }

        cin >> M;
        for(int i = 0; i < M; i++){
            int a;
            cin >> a;
            if(note1.find(a) != note1.end()) {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        }
    }

    return 0;
}
