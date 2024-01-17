#include <bits/stdc++.h>
using namespace std;

string s;

int main(){
    cin>> s;

    int ret;

    for(int i = 0; i < s.size()/2 ; i++)
    {
        if(s[i]== s[s.size()-1-i]){
            ret = 1;

        }else{
            ret = 0;
            break;
        }
    }
    cout << ret;
}