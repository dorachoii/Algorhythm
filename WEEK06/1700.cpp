#include <bits/stdc++.h>
using namespace std;

int n, k, a;
queue<int> q;
vector<int> plug;
int cnt;

int main(){
    cin >> n >> k;

    for(int i = 0; i < k ; i++){
        cin >> a;
        list.push_back(a);
    }

    while(!q.size()){
        bool isPluged = false;

        for(int b : plug){
            if(q.front() == b) 
            isPluged = true;
        }

        if(!isPluged){
            if(plug.size() > n){
            
            // 뒤에 만약 q.font와 같은 게 있다면 plug에서 다른 것 중 하나를 뺀다.
            plug.erase(plug.begin() + 1);
            cnt++;

            plug.push_back(c);
            q.pop();
        }else{
            plug.push_back(c);
            q.pop();
        }
        
        }
}
cout << cnt;
}