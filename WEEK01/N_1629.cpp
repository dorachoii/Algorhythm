#include <bits/stdc++.h>
using namespace std;

int a,b,c;

long multiply(int n){
    if(n == 1) return a;
    return (a * multiply(n-1))%c;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    cin >> a >> b >> c;

    long result = multiply(b);

    cout << result;
}

// 시간초과도 아니고 틀린 이유가 뭐지?
// 자료형 잘 모르겠네...
// 제곱을 구하는게 아니라 몇번 곱하는 거야 바보..
// long long result = pow(a,b);
// 재귀 왜 틀림?
// 제곱수도 맞는 말임.
//왤케 쉬운 문제를 냈나 했더니 또 이유가 있고
// overflow때문에 음수값이 나오기 때문