#include <bits/stdc++.h>
using namespace std;

int k, a[26];
string n, ret = "";

int main()
{

    cin >> k;

    for (int i = 0; i < k; i++)
    {
        cin >> n;
        a[n[0] - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (a[i] >= 5)
        {
            ret += (char)(i + 'a');
        }
    }

    if (ret.empty())
        cout << "PREDAJA";
    else
        cout << ret;
}