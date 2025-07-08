//짝짓기 문제는 stack
//오른쪽으로 탐색
// 오큰수가 나오기 전 탐색한 수들을 담아뒀다. 결정이 되면 그때 오큰수 ret은 배열

#include <bits/stdc++.h>
using namespace std;
int n, a[1000004], ret[1000004];
stack<int> s;

int main(){
    cin >> n;

    memset(ret, -1, sizeof(ret));

    for(int i = 0; i < n; i++){
        cin >> a[i];

        while(s.size() && a[s.top()]<a[i]){
            ret[s.top()] = a[i];
            s.pop();
        }
        s.push(i);
    }

    for(int i = 0; i < n; i++) cout << ret[i] << " ";
}
