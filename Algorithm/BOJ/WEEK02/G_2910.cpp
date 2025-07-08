#include <bits/stdc++.h>
using namespace std;

//c가 주어지는 이유가 뭘까나

int n,c,k;
vector<int> a;  // 입력 배열
int b[1004][2]; // b[값][개수]

vector<int> cc; // 해당 개수의 요소들 저장할 벡터

int main(){

    cin >> n >> c;

    for(int i = 0; i < n; i++){
        cin >> k;

        a.push_back(k);
    }

    // b[값][개수]
    for(int i = 0; i < a.size(); i++){
        b[a[i]][0] = a[i];
        b[a[i]][1]++;
    }
    
    // mx 값 부터 하나씩 줄여가며 탐색
    int mx = 0;

    for(int i = 0; i < c+1; i++){
        mx = max(mx, b[i][1]);
    }   

    while(mx >0){
        //cout << "현재 max값은 " << mx<<'\n';

        int cnt = 0;
        // 벡터 초기화
        cc.clear();

        for (int i = 0; i < 1004; i++)
        {
            if (b[i][1] == mx ) {

                for(int j = 0; j < a.size(); j++){
                    if(a[j]==b[i][0]){
                        
                    }
                }
                cnt++;
                cc.push_back(b[i][0]);
            }
        }

        cout << "max인 요소는 " << cnt << " 개" <<'\n';
        cout << "현재 cc에 들어있는 요소는 ";

        for(int a : cc){
            cout << a << " ";
        }
        cout <<'\n';


        // 순차 출력이 문제. 
        for(int i = 0 ; i < cnt; i++){
            for (int k = 0; k < mx; k++){
                cout << a[cc[i]] << " ";
                break;
            }
        }

        mx--;
    }

}