#include <bits/stdc++.h>
using namespace std;

int n, k, a, b, Dcnt, Ocnt;

// 5 10 20 이렇게 sum합을 구해두고 그걸 빼고 나머지를 구하는 느낌?
// 구간합

int oneMove(int a, int b)
{
    //cout << "현재 a :" << a << "b :" << b << '\n';
    //cout << "1칸 이동"<<'\n';

    if(a==b) return Ocnt;

    Ocnt++;
    if(a>b){
        return oneMove(a - 1, b);
    }else{
        return oneMove(a + 1, b);
    }
    
}

int doubleMove(int a, int b){

    //cout <<"현재 a :" << a << " b :" << b<<'\n';
    //cout << "현재 거리는 " << abs(b-a) << '\n';

    if(abs(b - a) < abs(b-2*a)) {
        return Dcnt+ oneMove(a,b);}

    Dcnt++;
    //cout << "2배 이동" << '\n';
    return doubleMove(2 * a, b);
}



int main(){

    cin >> n >> k;

    n >= k ? (a = k, b = n) : (a = n, b = k);

    cout << doubleMove(a,b)-1;
    

}
