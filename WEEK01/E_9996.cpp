#include <bits/stdc++.h>
using namespace std;

int n;
string s, f;
char start, endd;

int main()
{

    cin >> n;
    cin >> s;

    //start = s[0];
    //endd = s[2];

    for (int i = 0; i < n; i++)
    {
        cin >> f;

        if (f.size()>1 && s[0] == f[0] && s[2] == f[f.size()-1])
        {
            cout << "DA"<<'\n';
        }
        else
        {
            cout << "NE"<<'\n';
        }
    }
}