#include <bits/stdc++.h>
using namespace std;
// 10진수를 2진수로 바꾸는 방법!
int n, cnt, temp;
stack<int> stk;

int main(){
    cin >> n;

    while(n != 0){
        if(n %2 == 1){
            stk.push(1);
            cnt++;
        }else{
            stk.push(0);
        }
        n/=2;
    }

    cout << cnt;
    
}

