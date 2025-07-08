#include <bits/stdc++.h>
using namespace std;

string s = "*";
string t = " ";

int main(){
    int n;
    cin >> n;

    for(int i = 0 ; i <  n ; i++){
        string l;

        for(int j = 0; j < n-1-i; j++){
            l+= t;
        }
        
        for(int k = 0; k < 2*i+1; k++){
            l+= s;
        }
        
        for(int j = 0; j < n-1-i; j++){
            l+= t;
        }
        cout << l <<'\n';
    }

    for(int i = 0 ; i < n-1 ; i++){
        string l;

        for(int j = 0 ; j < i+1; j++ ){
            l+=t;
        }

        for (int j = 0; j < 2 * (n - 1) - 2 * i -1; j++)
        {
            l+=s;
        }

        for(int j = 0; j <i + 1; j++){
            l+=t;
        }
        cout << l <<'\n';
    }
}