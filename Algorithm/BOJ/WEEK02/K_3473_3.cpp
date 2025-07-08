#include <bits/stdc++.h>
using namespace std;

int main(){
     int n;
     cin >> n;

     for(int i = 0; i < n; i++){
        int k;
        cin >> k;

        int five = 0;
        int m = 5;
        
        five = k/5;

        while(k / 5 * m >0){
            if(k > 5*m){
                five -= k / 5 * m;
                m *= m;
            }
            break;        
        } 

        cout << five <<'\n';


     }
}