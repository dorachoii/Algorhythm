#include <bits/stdc++.h>
using namespace std;

// 1. 뒤집어보거나
// 2. 붙여보거나
// 3. 세로로 나열해보거나

int n, ret;
string s;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> s;

        stack<char> stk;
        
        for(char a : s){
            if(stk.size() && stk.top()==a) stk.pop();
            else stk.push(a);
        }

        if(stk.size()==0) ret++;
    }
    cout << ret << "\n";


    return 0;
}