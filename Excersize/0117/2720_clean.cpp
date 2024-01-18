#include <bits/stdc++.h>
using namespace std;

int q = 25;
int d = 10;
int n = 5;
int p = 1;

int qq,dd,nn,pp;

int T, t;


// * 이거 재귀함수로 바꿔보기?

int main(){
    
    //getline(cin,T);     //*getline 문자열받을 때
    cin>>T;
    cin.ignore();

    for(int i = 0; i <T; i++){

        //getline(cin,t);
        cin>>t;

        qq = t/q;
        dd = t%q/d;
        nn = t % q%d /n;
        pp = t%q%d%n;

        cout << qq << " " << dd << " " << nn << " " << pp << '\n';
    }



}