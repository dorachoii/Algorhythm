//수빈 : 뮤탈리스크 1개
//강호 : SCV N개

// m : 1 , s : 3
// 9,3,1
// 순열

// 우선 경우의 수 다 하겠음 순열 dowhile안쓰고 일단 하겠음

#include <bits/stdc++.h>
using namespace std;

int n, scvHP;
vector<int> hp;
int a[3] = {9,3,1};

int main(){

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> scvHP;
        hp.push_back(scvHP);
    }
    
    int cnt = 0;

    while(!hp.empty()){
        sort(hp.begin(), hp.end(), greater<int>());

        for (int i = 0; i < hp.size(); i++)
        {
            hp[i] -= a[i];
        }
        cnt++;

        hp.erase(remove_if(hp.begin(), hp.end(), [](int x)
                           { return x <= 0; }),
                 hp.end()); // 체력이 0 이하인 SCV 제거
    }
    
    cout << cnt;

}

// 꼭 가장 큰 것에 9 3 1 을 빼주는 것이 공식이 아님..