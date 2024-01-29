#include <bits/stdc++.h>
using namespace std;

int N, k, sum;
vector<int> kk;

int main(){
    cin >> N;

    for(int i = 0; i < N ; i++){
        cin >> k;

        if(k){
            kk.push_back(k);
            sum += k;
        }else{
            sum -= kk.back();
            kk.pop_back();           
        }
    }

    cout << sum;
    
}