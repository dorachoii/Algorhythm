#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, x, y, minY = 10000, minX = 10000, maxY = -10000, maxX = -10000;
    cin >> N;

    while (N--)
    {
        cin >> x >> y;
        
        minY = min(minY, y);
        minX = min(minX, x);
        maxY = max(maxY, y);
        maxX = max(maxX, x);
    }
    cout << (maxX - minX) * (maxY - minY);
}