#include <bits/stdc++.h>
using namespace std;

int h,w, a[101][101], ret[101][101];
char s;

// 분명 뭔가 더 줄일 수 있는 방안이 있을 거같은데

int main(){

    cin >> h >> w;

    for(int i = 0; i < h ; i++){
        for(int j = 0; j < w; j++){
            cin >> s;
            if (s == 'c')
            {
                a[i][j] = 1;
            }
        }
    }

    //구름을 이동시키며 판단할지, 고정좌표 기준으로 구름이 얼마나 떨어진지로 판단할지

    // 구름이 있다면 cnt = 0
    // 없다면, 앞에 구름이 있었다면 ++ 증가
    

    for(int i = 0; i < h; i++){
        bool hasCloud = false;
        int cnt = -1;

        for(int j = 0; j < w; j++){

            if(j == 0 && a[i][j] ==1) cnt =0;
            
            

            if(a[i][j]==1){ 
                hasCloud = true ;             
                cnt = 0;
                ret[i][j] = cnt;
                cout << ret[i][j] << " ";
                continue;          
            }



            if(hasCloud) cnt++;
            ret[i][j] = cnt;
            cout << ret[i][j] << " ";
        }
        cout << '\n';
    }
    
    

}