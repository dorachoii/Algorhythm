#include <iostream>
using namespace std;

const int max_n = 10;
int a[max_n];
vector<int>b = {1,3,4,2,5};

vector<pair<int, int>>b;

int main() {
    memset(a, 0,sizeof(a));
    // for(int i = 0; i < 10; i++){
    //     cout << a[i] << " ";
    // }

    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    for(int i = 0; i < b.size(); i++){
        cout << b[i] << " ";
    }
}