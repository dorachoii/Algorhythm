#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<pair<int, int>> points;
    int x, y;

    for(int i = 0; i < 3; i++){
        cin >> x >> y;
        points.push_back({x,y});
    }

    float dx1 = points[1].first - points[0].first;
    float dy1 = points[1].second - points[0].second;

    float dx2 = points[2].first - points[1].first;
    float dy2 = points[2].second - points[1].second;

    if(dy1/dx1 == dy2/dx2) cout << 0 << endl;
    if(dy1/dx1 < dy2/dx2) cout << 1 << endl;
    if(dy1/dx1 > dy2/dx2) cout << -1 << endl;

    return 0;
}