#include <bits/stdc++.h>
using namespace std;

// 성냥개비를 모두 사용해서 만들 수 있는 가장 작은 수와 큰 수

int t, n, minn, maxx;

// 1,2,3,4,5,6,7,8,9,0
int[] sticks = {2,5,5,4,5,6,3,7,6,6};

// 1,7,4,2,3,5,6,9,0,8
// 2,3,4,5,5,5,6,6,6,7

// 최소합: 5

// 1자리수: max가지수: 7 
// 2자리수: 7 이상이면, 자리수를 늘리는 게 가장 좋으니까 1을 늘리는 것을 택한듯! 
// min 가지수: 4 11

// min을 만드는 방법
// : 7 이하인 경우 최대한 한자리로 끝
// : 7 이상인 경우 2빼고 홀수라면: 8
// : 7 이상인 경우 2빼고 짝수라면: 

// max를 만드는 방법
// : 5 이상인 경우 : 2자리로 구성 71
// : 

int main(){
    cin >> t;

    for(int i = 0; i < t; i++){
        cin >> n;

        if(n <= 7){
            if(n == 2){
                minn = 1;
                maxx = 1;
            }else if(n == 3){
                minn = 7;
                maxx = 7;

            }else if(n == 4){
                minn = 4;
                maxx = 11;

            }else if(n == 5){
                minn = 2;
                maxx = 71;

            }else if(n == 6){
                minn = 6;
                maxx = 77;

            }else if(n == 7){
                minn = 8;
                maxx = 771;
            }
        }else{
            
        }
    }

}