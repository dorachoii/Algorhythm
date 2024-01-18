#include <bits/stdc++.h>
using namespace std;

int n, cnt;
string t;


int main(){

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> t;

        bool isGroup = true; // true :1 , false:0;

        if(t.length()>1){
            for (int j = 1; j < t.length(); j++)    //strlen(t) 사용가능
            {
                if (t[j] == t[j - 1])
                {

                    continue;
                }
                else
                {
                    for (int k = j - 1; k >= 0; k--)
                    {
                        if (t[j] == t[k])
                        {
                            isGroup = false;
                            break;
                        }
                    }
                }
            }
        }
        

        cnt += isGroup;
    }

    cout << cnt;
    
}