#include <bits/stdc++.h>
using namespace std;
int N;

int main(){

    cin >> N;

    int x[N],y[N];

    for(int i = 0 ; i < N ; i++){
        cin >> x[i];
        cin >> y[i];
    }

    int minx = *min_element(x, x + N);
    int maxx = *max_element(x, x + N);
    int miny = *min_element(y, y + N);
    int maxy = *max_element(y, y + N);

    cout << (maxx - minx) * (maxy - miny);

}