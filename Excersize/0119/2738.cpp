#include <bits/stdc++.h>
using namespace std;

int n,m,a;
int arr1[101][101], arr2[101][101], ret[101][101];

int main(){

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a;
            arr1[i][j] = a; 
        }
    }

    for(int i = n; i < n+n; i++){
        for(int j = 0; j < m; j++){
            cin >> a;
            arr2[i-n][j] = a;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            ret[i][j] = arr1[i][j] +arr2[i][j];
            cout << ret[i][j] << " ";
        }
        cout << '\n';
    }

}