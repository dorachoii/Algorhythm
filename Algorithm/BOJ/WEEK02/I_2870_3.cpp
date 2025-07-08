#include <bits/stdc++.h>
using namespace std;

// 숫자인지 여부를 판단하는 함수
// 빅인트 구현해야함..
// string으로 처리하기

bool isNum(char c) {
    return c >= '0' && c <= '9';
}

int main() {
    bigint n;
    cin >> n;

    vector<bigint> ret; // 추출한 숫자들을 저장할 벡터

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        string numS = ""; // 숫자를 문자열로 축적할 변수

        for (char c : s) {
            if (isNum(c)) { // 현재 문자가 숫자인 경우
                numS += c; // 숫자를 축적
            } else { // 현재 문자가 숫자가 아닌 경우
                if (!numS.empty()) { // 숫자를 축적한 경우에만
                    // 앞에 0이 여러 개 있는 경우 처리
                    
                    ret.push_back(stoi(numS));
                    numS = ""; // 숫자를 축적한 문자열 비움
                }
            }
        }

        // 마지막에 숫자가 남아있는 경우 처리
        if (!numS.empty()) {
            
            ret.push_back(stoi(numS));
            numS = "";
        }
    }

    // 추출한 숫자들 정렬
    sort(ret.begin(), ret.end());

    // 정렬된 숫자들 출력
    for (bigint num : ret)
    {
        cout << num << '\n';
    }

    return 0;

    //stoi를 저장할 때 int를 사용하면 out of range 가 발생할 수 있다.
}
