#include <bits/stdc++.h>
using namespace std;

int t,n;
string a,b;

int main(){

    cin >> t;

    while(t--){
        map<string,int> _map;
        cin >> n;

        for(int i = 0; i < n; i++){
            cin >> a>> b;
            _map[b]++;
        }

        long long ret = 1;
        for(auto c: _map){  //순회할 수 있구나
            ret *=((long long)c.second + 1);    
            // 경우의 수는 그냥 long long 선언하라.
            // 없는 경우도 넣어야 하니까 +1 해준 것
        }
        ret--;
        // 전체 경우의 수에서 모든 걸 다 쓴 경우의 수를 뺴주면 됨.
        cout << ret << "\n";
    }



}