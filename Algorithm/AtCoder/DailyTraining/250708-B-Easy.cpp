#include <iostream>
#include <string>
using namespace std;

//偶数(ぐうすう)：짝수

int main() {
    string s;
    cin >> s;

    for (int i = 1; i < s.length(); i+=2) {
        if(s[i] == '1') {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}