#include <bits/stdc++.h>
using namespace std;

int from, to, n, idx = 0, ret =1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>> n;

    vector<pair<int, int>> v;

    for(int i = 0; i < n; i++){
        cin >> from >> to;
        v.push_back({to, from});
    }

    sort(v.begin(), v.end());

    from = v[0].second; // 1
    to = v[0].first; //4

    for(int i = 1; i < n; i++){
        //3 < 4
        // 0 < 4
    
        if(v[i].second < to) continue;

        // 5 > 4
        from = v[i].second; //7
        to = v[i].first;    //5
        ret++; 
    }

    cout << ret << '\n';
    return 0;
}