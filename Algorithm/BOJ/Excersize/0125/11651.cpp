#include <bits/stdc++.h>
using namespace std;

int N, x, y;


int main(){
    
    cin >> N;
    
    int t[N][2];
    vector<int> yy;

    for(int i = 0; i < N; i++){
        cin >> x >> y;
        t[i][0] = x;
        t[i][1] = y;

        yy.push_back(y);
    }

    sort(yy.begin(), yy.end());

    for(int i = 0 ; i < N; i++){
        int cnt = 0;
        int k = 0;
        vector<int> xx;

        for(int j = 0; j < N ; j++){
            if(yy[i] == t[j][1]) {
                cnt++;
                k = j;
                xx.push_back(t[j][0]);
                }
        }

        if(cnt == 1){
            cout << t[k][0] << " " << yy[i] << '\n';
        }else{
            sort(xx.begin(), xx.end());

            for(int a : xx){
                cout << a << " " << yy[i] << '\n';
            }
            
        }
    }

}