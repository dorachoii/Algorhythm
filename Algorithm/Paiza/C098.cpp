#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int m;
    cin >> m;

    vector<vector<int>> b(m);

    for (int i = 0; i < m; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            int x;
            cin >> x;
            b[i].push_back(x);
        }
    }

    for(int i = 0; i< m; i++){
        int m = min(a[b[i][0]-1],b[i][2]);
        a[b[i][0]-1] -= m;
        a[b[i][1]-1] += m;
    }

    for(int i = 0; i < n; i++){
        cout << a[i] << endl;
    }
}
