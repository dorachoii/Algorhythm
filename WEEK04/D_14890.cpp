#include <bits/stdc++.h>
using namespace std;


int n, l, cnt;
int a[101][101];
vector<int> v, v2;
int s[101];
int prevv = 0;

void check(vector<int> b){
    bool isAllSame = true;
    bool isSlope = true;

    prevv = b[0];

    for(int i = 1; i < b.size(); i ++){
        if(prevv != b[i]){
            cout <<"모두 같지 않음!"<<'\n';
            isAllSame = false;

            if(i+l < b.size()){
                //cout << "aa"<<'\n';

                cout << b[prevv] << "/" << b[prevv + l] <<'\n';
                cout << "둘의 높이 차는" << abs(b[prevv] - b[prevv +l]) <<'\n';

                if(abs(prevv - b[i +l]) != 1){

                    cout <<"경사로로 갈 수 없음!"<<'\n';
                    isSlope = false;
                    break;
                }
                else
                // 경사를 설치할 수 있다면!
                {
                    cout << "높이 차가 1이다"<<'\n';
                    // 이전에 경사로가 설치되었다면 false
                    if(s[prevv] == 1){
                        isSlope = false;
                    }

                    // 경사를 설치!
                    for(int i = prevv ; i < prevv + l ; i++){
                        s[i] = 1;
                    }
                }
            }
        }
        prevv = b[i];
    }

    

    // 모두 같으면 cnt ++
    // 서로 다른데, l개 뒤와 높이가 1차이라면 cnt++;
    if(isAllSame || isSlope) {
        cnt++;
        cout <<"조건 만족!"<<'\n';
    }
    
}

int main(){
    cin >> n >> l;

    for(int i = 0; i < n ;i ++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    //행부터 검사
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n; j++){
            v.push_back(a[i][j]);
            v2.push_back(a[j][i]);
        }
        cout << i << "번째 행 검사중" <<'\n';
        check(v);

        cout << i << "번째 열 검사중" <<'\n';
        check(v2);

        v.clear();
        v2.clear();
        memset(s, 0, sizeof(s));
    }

    cout << cnt;
}






