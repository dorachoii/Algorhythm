#include <bits/stdc++.h>
using namespace std;

int n, s;
int a[51];
bool hasT = false;

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> s;
        a[s]++;
    }

    for (int i = 51; i >= 0; i--)
    {
        if (a[i] == i)
        {
            cout << i;
            hasT = true;
            return 0;
        }
    }

    if (!hasT)
    {
        cout << -1;
    }
}
