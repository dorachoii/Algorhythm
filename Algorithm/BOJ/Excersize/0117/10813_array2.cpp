#include <bits/stdc++.h>
using namespace std;

int p[101],n,m,i,j;

int main(){

   cin >> n >> m;

   for(int x = 0; x < n ; x++){
    p[x] = x+1;
   }

    for(int x = 0; x < m; x++){
        cin >> i >> j;

        int a,b;

        a = p[i-1];
        b = p[j-1];

        p[j-1] = a;
        p[i-1] = b;             // 여기서도 t하나로만 바꿀 수 있는 로직
    }

    for(int x = 0; x< n; x++){
        cout << p[x] << ' ';
    }
    
}