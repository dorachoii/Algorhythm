#include <bits/stdc++.h>
using namespace std;

int n, mnNutri[4], a[16][5], nutri[4], price, mnPrice = 1000;

vector<int> selectedF;
vector<vector<int>> Fcombi;
vector<vector<int>> stsfFcombi;

int main() {
    // 음식 개수
    cin >> n;

    // 최소 영양소 
    for (int i = 0; i < 4; i++) {
        cin >> mnNutri[i];
    }

    // 음식 영양소 + 가격 배열 받기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> a[i][j];
        }
    }

    // 1. 조합 구하기
    // 조합으로 나올 경우의 수 Fcombi에 담기
    for (int i = 0; i < (1 << n); i++) {
        selectedF.clear();

        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                selectedF.push_back(j);
            }
        }
        Fcombi.push_back(selectedF);
    }

    // 2. 최소 조건 체크
    // Fcombi에서 최소 조건을 만족한다면 성공배열에 넣기

    for (vector<int> v : Fcombi) {
        // 선택된 조합에서

        memset(nutri, 0, sizeof(nutri));

        for (int aa : v) {
            for (int i = 0; i < 4; i++) {
                // 영양소의 합을 구하고
                nutri[i] += a[aa][i]; 
            }
        }

        bool isGood = true;

        // 모든 영양소가 최저조건을 만족한다면?
        for (int i = 0; i < 4; i++) {
            if (nutri[i] < mnNutri[i]) {
                isGood = false;
                break;
            }
        }

        if (isGood) {
            // 만족하는 조합배열에 또 넣기
            stsfFcombi.push_back(v);
        }
    }


    // 비용 구하기
    vector<int> idxs;
    int idx = 0;
    int mnIdx = 1000;

    for (vector<int> v : stsfFcombi) {
        
        price = 0;

        // 만족하는 콤비의 각 배열 인덱스의 비용을 더해준다.
        for (int e : v) {
            price += a[e][4];
        }

        // 최소를 갱신할 때, 갱신되는 인덱스를 저장해둔다.
        if (price < mnPrice) {
            mnPrice = min(price, mnPrice);
            idxs.clear();
            idxs.push_back(idx);
        } else if (price == mnPrice) { // 최소 비용이 같을 때에도 인덱스를 저장
            idxs.push_back(idx);
        }

        idx++;
    }

    cout << mnPrice << '\n';

    for (int a : stsfFcombi[idxs[0]]) {
        cout << a + 1 << " ";
    }
}
