#import <bits/stdc++.h>
#define z begin(s), end(s) 

using namespace std;

int main()
{
    int a = 0;
    string s;

    for (cin >> s; cin >> s; a += unique(z) == end(s))   
    {
        s.erase(unique(z), end(s));
        sort(z);
    }

    cout << a;
}
