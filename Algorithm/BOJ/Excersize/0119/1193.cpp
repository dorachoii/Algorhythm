#include <bits/stdc++.h>
using namespace std;

vector<int> a,b;
int s;

int main()
{
    cin >> s;

    a.push_back(1);


    for(int n = 1; n <= s; n++){
        for (int i = 1; i <= 2 * n + 1; i++)
        {
            a.push_back(i);
        }

        for (int i = 2 * n ; i > 0; i--)
        {
            a.push_back(i);
        }

        for(int i = 1; i <=2*n ; i++){
            b.push_back(i);
        }

        for(int i = 2*n-1 ; i>0; i--){
            b.push_back(i);
        }
    }

    cout << a[s-1] <<"/"<<b[s-1];

    return 0;
    
}