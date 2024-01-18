#include <bits/stdc++.h>
using namespace std;

int n;

int cnt(int n){
    if(n == 1) return 3;
    return 2* cnt(n-1) -1;
}

int main(){
    cin >> n;

    cout << cnt(n)*cnt(n);
}

