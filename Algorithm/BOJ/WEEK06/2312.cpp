#include <bits/stdc++.h>
using namespace std;

int t , a;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;

    for(int i = 0; i < t ; i++){
        cin >> a;

        for(int j = 2; j * j <= a; j++){
            int origin = a;
            int cnt = 0;
                while(a % j == 0) {
                    a/=j;
                    cnt++;
                }
                cout << j <<" " << cnt << '\n';
            
        }

        if(a != 1){
            cout << a << " "<< 1 <<'\n';
        }

    }
}