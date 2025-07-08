#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a,b,c;
ll go(ll a, ll b){
    if(b==1) return a %c;
    ll ret = go(a,b/2);
    ret = (ret * ret) %c;
    if(b%2) ret = (ret * a) %c; // 홀수일 때는 한 번 더 곱한다.
    return ret;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> a >>b>>c;
    cout << go(a,b) << "\n";
    return 0;

}

// 문제의 최대 최소범위를 봐라.
//  a,b,c 20억 이하

// 2 ^4승을 구할 때 2^2를 변수에 담아두고 곱하면 4번 곱할 거 2번 곱해도 됌
// log64 번 곱해주면 된다.
// 그냥 곱하면 20억, log20억이 되는 거

// 모듈러 연산도 필요. 나머지
// (a+b)%c = a%c + b%c
// (a*b)%c = a%c * b%c

// 20억 * 20억은 무조건 long long 범위 벗어나므로
//  곱할 때마다 %c를 해준다

// 다 곱하고서 %c를 하면 오버플로우
// 따라서 %c 먼저해주면서 계산
