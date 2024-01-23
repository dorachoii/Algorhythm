#include <bits/stdc++.h>
using namespace std;

//문자열로 읽어서 stoi
//A:65 - 55로 계산

string N;
int B, n, l, k =1, sum;;



int main(){
    cin >> N >> B;

    l = N.length()-1;

    for(char s : N){
        if((int)s > 64){
            n = (int)s - 55;
        }else{
            //n = stoi(s);
            n = (int)s - 48;
        }

        for(int i = 0; i < l; i++){
            k *=B;
        }
        
        l--;
        
        sum += k*n;
        k = 1;
    }

    cout << sum;

}