#include <bits/stdc++.h>
using namespace std;

int n,m,j,prevv,nextt,cnt,k;
int start, endd;

//최대최소 넘어서 이동하는 거 체크

int main(){

    cin >> n >> m >> j >> prevv;

    for(int i = 0; i < j-1; i++){
        cin >> k;
        nextt = k;

        start = prevv;
        endd = prevv + m - 1;

        if(nextt <= endd && nextt >= start ){
            continue;  

        }
        else if(prevv < nextt){
        // 오른쪽 이동
            if(endd >=nextt){
                continue;
            }else{
                for(int j = endd; j < nextt; j++){
                    start++;
                    endd++;
                    cnt++;
                    //cout << "현재 바구니 시작 점은 " << start << '\n';
                    cout << "현재 바구니 끝 점은 " << endd << '\n';
                    cout << "오른쪽 이동합니다'\n";
                }
            }
        }else{
            // 왼쪽 이동
            if(start <= nextt){
                continue;
            }else{
                for(int j = start; j > nextt; j--){
                    start--;
                    endd--;
                    cnt++;
                    cout << "현재 바구니 시작 점은 " << start << '\n';
                    //cout << "현재 바구니 끝 점은 " << endd<< '\n';
                    cout << "왼쪽 이동합니다'\n";
                }
            }

        }

        prevv = nextt;
        } 

    cout << cnt;


}