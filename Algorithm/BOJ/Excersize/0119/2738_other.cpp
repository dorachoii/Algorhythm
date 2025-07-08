
#include <iostream>
using namespace std;
int arr[101][101];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n * 2; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int t;
            cin >> t;
            arr[i % n][j % m] += t;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
}