#include <bits/stdc++.h>
using namespace std;

int c[6] = {1,1,2,2,2,8};
int a[6];

int k;

int main(){

    for(int i = 0; i < 6; i++){
        cin >> k;

        a[i] = c[i] -k;
        cout<< a[i] <<" ";
    }
    
}