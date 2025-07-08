#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000;

int visited[MAX + 4];
long long cnt[MAX +4];
vector<int> route[MAX];

int main(){
    int n, k;
    cin >> n >> k;

    if(n==k){
        puts("0");
        puts("1");
        return 0;
    }

    visited[n] = 1;
    cnt[n] = 1;

    queue<int> q;
    q.push(n);
    route[0].push_back(n);

    int i = -1;

    while(!q.empty()){
        int now = q.front();
        q.pop();
        i++;
        cout << "현재 i는 " << i << '\n';

        for(int next: {now -1, now +1 , now *2}){
            if(0 <= next && next <=2*k){
                if(!visited[next]){
                    q.push(next);
                    visited[next] = visited[now] +1;
                    cout << next << "에 처음 방문하고 누적된 이동은 " << visited[next] <<'\n'; 
                    cnt[next] += cnt[now];
                    route[i].push_back(next);
                    cout << next << " 벡터에 저장 "  << '\n';
                }else if(visited[next]== visited[now]+1){
                    cnt[next] += cnt[now];
                    
                }
            }
        }
        route[i].push_back(k);
    }

    cout << visited[k]-1 << '\n';
    for(int a : route[0]){
        cout << a <<" ";
    }
}