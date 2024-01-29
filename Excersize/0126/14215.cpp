#include <bits/stdc++.h>
using namespace std;
int a, b, c;

int main()
{
    cin >> a >> b >> c;

    int s[] = {a,b,c};
    sort(s, s+3);

    if(s[0]==s[1]&& s[1]==s[2]){
        cout << s[0] + s[1] + s[2];
    }else if(s[0]+s[1]>s[2]){
        cout << s[0] + s[1] + s[2];
    }else{
        if(s[0]+s[1] <=s[2]){
            cout << s[0] + s[1] + s[0] + s[1] -1;
        }
    }
}
