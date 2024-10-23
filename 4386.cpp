#include <bits/stdc++.h>
using namespace std;

pair<int, int> co[104];
int n, sum;

int length(int x, int y, int xx, int yy){
    int pw = pow(abs(xx - x),2) + pow(abs(yy - y), 2);
    return sqrt(pw);
}

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> co[i].first >> co[i].second;
    }

    for(int i= 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            sum += length(co[i].first, co[i].second, co[j].first, co[j].second);
        }
    }

    cout << sum;
   
}

// 입력 다르게 받아야 할듯!