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

        for(int i = 0; i < k-1; i++){
            int first = q.front();
            q.pop();
            q.push(first);
        }
        
        int toRemove = q.front();
        q.pop();
        v.push_back(toRemove);
    }


    cout << "<";
    for(int i = 0; i < v.size(); i++){
        if (i != 0) cout << ", ";
        cout << v[i];
    }
    cout << ">" << endl;

    return 0;
}
