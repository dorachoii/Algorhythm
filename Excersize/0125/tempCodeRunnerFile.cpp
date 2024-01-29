#include <bits/stdc++.h>
using namespace std;

int x,y,w,h;
int xx, yy,ret;

int main(){

    cin >> x >> y >> w >> h;

    yy = h - y;
    xx = w - x;

    xx>=yy ? xx<yy : ret = yy : ret = xx;

    cout << ret;
}