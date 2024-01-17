#include <bits/stdc++.h>
using namespace std;

int n,m;
int j,k,l;

vector<vector<int>> v;

vector<int> baguni;

int main(){

    cin >> n >> m;
    baguni.resize(n, 0);            //*resize안했더니 segment fault발생

    for(int i = 0; i < m ; i++){
        cin >> j >> k >> l;

        vector<int> temp;
        temp = {j,k,l};
        v.push_back(temp);
        //cout << "2차원 배열의" << i << "번째 행의 값은" << j << k << l << '\n';
    }

    //cout << "n은" << n << '\n';
    //cout << "m은" << m << '\n';

    for(int i = 0; i < m ; i++){
        for(int j = v[i][0]-1;j < v[i][1]; j++ ){
            baguni[j] = v[i][2];
        }
    }

    for(int i = 0; i < n; i++){
        cout<< baguni[i] << " ";
    }
    cout << '\n';

    return 0;
}