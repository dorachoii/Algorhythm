#include <bits/stdc++.h>
using namespace std;

string s;
// a: 아스키 코드 97
// z: 아스키 코드 122

int ret[26];

int main()
{
    cin >> s;

    for (int i = 0; i < 26; i++)
    {
        ret[i] = -1;
    }


    int i = 0;

    for (char c : s)
    {
        if (c < 123 && c > 96)
        {
            if(ret[c-97]==-1){
                ret[c - 97] = i;
            }
            
        }
        i++;
    }

    for (int i = 0; i<26; i++)
    {
        cout << ret[i] << " ";
    }
}