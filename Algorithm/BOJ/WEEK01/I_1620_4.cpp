#include <bits/stdc++.h>
using namespace std;

int N, M;
map<string,int> mp;

map<int, string> mpp;

string s;

int main(){

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        cin >> s;
        mp.insert({s,i+1});
        mpp.insert({i+1,s});
    }

    for(int i = 0; i < M; i++){
        cin >> s;
        if (!(atoi(s.c_str()))){
            cout << mp[s] << '\n';
        }else{
            int k = stoi(s);
            cout << mpp[k] << '\n';
        }
    }

}
//또 시간 초과 왜?
// gpt 에서 unordered map 사용한 거 봤는데 이거도 시간초과 어떻게 풀라는거냐!
// value로 key에 접근하는 방법 O(N)이 걸리므로 자료구조가 두 가지가 필요하다.