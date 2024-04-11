// 우선 6개 중에 켜고 끄는 것부터
#include <bits/stdc++.h>
using namespace std;


int n, mnNutri[4],a[16][5], nutri[4], price, mnPrice = 1000;
vector<int> selectedF;
vector<vector<int>> Fcombi;
vector<vector<int>> stsfFcombi;

int main(){
    cin >> n;

    for(int i = 0; i < 4; i++){
        cin >> mnNutri[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 5; j++){
            cin >> a[i][j];
        }
    }

    // n 콤비네이션 만들어 vector에 넣기
    for(int i = 0; i < (1 << n); i++){
        selectedF.clear();

        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                selectedF.push_back(j);
            }
        }
        Fcombi.push_back(selectedF);
    }

    // for(vector<int> v : Fcombi){
    //     for(int a : v){
    //         cout << a <<" ";
    //     }
    //     cout <<'\n';
    // }


    // 최소조건 만족하는지 체크하기
    // Fcombi에서 최소 조건을 만족한다면 성공배열에 넣기
    for(vector<int> v : Fcombi){
        memset(nutri, 0, sizeof(nutri));

        for(int aa : v){
            for(int i = 0; i < 4; i++){
                nutri[i] += aa;
            }   
        }
        bool isGood = true;

        for(int i = 0; i < 4; i++){
            if(nutri[i] < mnNutri[i]) {
                isGood = false;
                break;
            }
        }

        if(isGood){
            stsfFcombi.push_back(v);
        }
    }

    
    // 비용 구하기
    int idx = 0;
    int mnIdx = 1000;

    for(vector<int> v : stsfFcombi){
        idx++;
        price = 0;

        for(int e : v){
            price += a[e][5];
        }

        if(price < mnPrice){
            mnPrice = min(price, mnPrice);
            mnIdx = idx;
        } 
    }

    cout << mnPrice <<'\n';

    for(int a : stsfFcombi[mnIdx]){
        cout << a << " ";
    }
}

