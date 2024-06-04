#include <bits/stdc++.h>
using namespace std;

int N, K;
string s;

set<char> setc;
set<char> v = {'a', 'c', 't', 'i', 'n'};
vector<string> vv;

int main(){
    cin >> N >> K;

    if(K < v.size()) {
        cout << "0";
        return 0;
    }

    for(int i = 0; i < N; i++){
        cin >> s;
        if(s.size() <= 8) {
            vv.push_back("");
        } else {
            string cs = s.substr(4, s.size() - 8);
            vv.push_back(cs);
            
            for(char c : cs){
                if(setc.find(c) == setc.end()){
                    if(v.size() < K){
                        v.insert(c);
                    } else {
                        setc.insert(c);
                    }
                }
            }
        }
    }

    while(v.size() < K && !setc.empty()){
        v.insert(*setc.begin());
        setc.erase(setc.begin());
    }

    int cnt = 0;
    for(string s : vv){
        for(char c : s){
            if(v.find(c) != v.end()){
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}
