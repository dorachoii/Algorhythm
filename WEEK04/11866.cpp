#include <bits/stdc++.h>
using namespace std;

int n, k;
queue<int> q;
vector<int> v;

int main(){
    cin >> n >> k;

    for(int i = 1; i <= n; i++){
        q.push(i);
    }

    while(!q.empty()){

        if(q.size() < 3){
           int aa = q.front();
           q.pop();
           v.push_back(aa);
        }

        int first = q.front();
        q.pop();
        q.push(first);

        int second = q.front();
        q.pop();
        q.push(second);

        int third = q.front();
        q.pop();
        v.push_back(third);
    }

    cout << "<";
    for(int i = 0; i < v.size(); i++){
        if (i != 0) cout << ", ";
        cout << v[i];
    }
    cout << ">";

    return 0;
}
