#include <bits/stdc++.h>
using namespace std;

int x,y,w,h;
int xx, yy;

int main(){

    cin >> x >> y >> w >> h;

    yy = h - y;
    xx = w - x;

    yy>=y ? yy=y : yy=yy;
    xx>=x ? xx=x : xx=xx;
    xx >= yy ? cout << yy : cout << xx; // min({x,w-x,h-y,y})최솟값 찾는 알고리즘
}