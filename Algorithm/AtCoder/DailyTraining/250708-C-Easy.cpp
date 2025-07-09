#include <iostream>
using namespace std;

int main() {
    long long a;
    long long sum = 0;
    long long power = 1;

    for (int i = 0; i < 64; i++) {
        cin >> a;
        sum += a * power;
        power *= 2;
    }

    cout << sum << '\n';
    return 0;
}
