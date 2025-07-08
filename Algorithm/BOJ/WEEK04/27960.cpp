//"난 너희 둘 중 한 명만 맞힌 표적은 다 맞혔는데, OR
//너희 둘 다 못 맞히거나 둘 다 맞힌 것은 전부 안 맞혔어." AND

#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int d;

int main(){
    cin >> a >> b;
    
    // 다 맞힌 것 >> 꺼줘야 한다.
    //d = a & b;

    // 둘 중의 하나라도 참이면 참!
    //c = a | b;
    
    //c = c ^ d;
     
     c = a^b;
    cout << c;
}