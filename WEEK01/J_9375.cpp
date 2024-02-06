#include <bits/stdc++.h>
using namespace std;

int tc, n;
int typeCnt;
string s,type;
map<string, int> cody;



int main(){

    cin >> tc;

    for(int i = 0 ; i < tc; i++){
        cin >> n;
        int k = 1, m = 0;
        for(int j = 0 ; j < n; j++){
            cin >> s >> type;
            if (cody[type] == 0)
            {
                typeCnt++;
            }
            cody[type]++;
            m++;
        }

        k *=m;

        cout << k-1;
        //type은 string으로 했을 때의 문제 발생. 순차 점검이 불가하네.
        //뽑는 개수를 늘려가며 더해줘야하는데.. 이걸 재귀로? 어렵다.
        //수학과 코딩의 다른 점을 알았음..
        //수학문제는 일단 체력으로라도 풀면되었는데 코딩은 슈퍼답이 필요함.. 모든 경우의 수를 커버할 수 있는 점화식을 짜야 하는 것임.
    }

}