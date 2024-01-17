#include <bits/stdc++.h>
using namespace std;

int p[101],n,m,i,j;

int main(){

    cin >> n >> m;

    for(int b = 1; b <= n; b++) p[b] = b;

    for(int a = 0; a < m; a++){
        cin >> i >> j;

        
            for(int k = 0; k < (j-i+1)/2; k++){
                int t = p[j - k];
                p[j - k] = p[i + k];
                p[i + k] = t;
            }           
        
    }

    for(int b = 1; b <= n ; b++) cout << p[b] <<' ';

}