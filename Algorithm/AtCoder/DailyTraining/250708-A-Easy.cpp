#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if(s[i] != t[i]) {
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}