// 한 칸 이동하거나, 2배 이동하거나 
// 한 칸 이동은 도착지와 위치 비교해서 좌우 
// 2배 이동은 도착지와 일정이상 넘어가면 끝나도록

#include <bits/stdc++.h>
using namespace std;

int n, k, cnt, mnMove = 987654321, mnCnt;

int oneMove(int s, int e){
    cnt++;

    if(s < e) return s+1;
    if(s > e) return s-1;
    else return e;
}

int doubleMove(int s, int e){

    if(abs(2*s - e) < s){
        cnt++;
        return 2*s;
    }
    else{
    return s;}
}

int move(int s, int e){

    if(s == e){
        if(mnMove == cnt) mnCnt++;
        mnMove = min(mnMove, cnt);

        return mnMove;
    }

    return move(oneMove(s,e),e);
    

}