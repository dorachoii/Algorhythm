#include <bits/stdc++.h>
using namespace std;

string a[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
string s;

size_t poss[8];

int cnt;

int main(){
    cin >> s;

    for(int i = 0; i < 8; i++){
        size_t pos = s.find(a[i]);
        poss[i] = pos;

        if(pos == string::npos) poss[i] = -1;
    }

    for(int i = 0; i < 8; i++){
        
       // 후와 비교해서 겹치지 않는지 검사
       if(poss[i] != -1){
           for (int j = i+ a[i].length -1 ; j < 8; j++)
           {
                if(poss[j]!=-1){
                    cnt++;
                    break;
                }
           }
       }else{
        cnt++;
       }
    }

    cout << cnt;
}