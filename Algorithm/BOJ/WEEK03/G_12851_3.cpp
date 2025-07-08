// 2배씩 되는 구간합을 집합 구해두고
// 구간합보다 1작을 때까지 처음에 onemove - double - one의 식으로 구성해보자.

#include <bits/stdc++.h>
using namespace std;

int n, k, a,b, psum[100001],Ocnt,Dcnt;

int oneMove(int a, int b){
    if(a == b) return Ocnt;

    for(int i = 1; i < 100000; i++){
        Dcnt++;
        if(abs(b-a)>= psum[i]){
            return oneMove(a*2*i,b);
            break;
        }
       
    }
    if (abs(b - a) > abs(b - 2 * a))
    {
        Dcnt++;
        return Dcnt + oneMove(2*a, b);
    }

    Ocnt++;

    if (a > b)
    {
        return oneMove(a - 1, b);
    }
    else
    {
        return oneMove(a + 1, b);
    }
    }

int main(){

    cin >> n >> k;
    n >= k ? (a = k, b = n) : (a = n, b = k);

    psum[1] = a;

    for (int i = 2; i <= 100000;  i++){
        psum[i] = psum[i-1] + 2*a;
    }

    cout << oneMove(a,b);
}