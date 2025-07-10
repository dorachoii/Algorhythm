#include <iostream>
using namespace std;

int main() {
    long long x;
    cin >> x;

    int n = 1;
    long long factorial = 1;

    while(x !=  factorial){
        factorial *= n;
        n++;
    }

    cout << n-1 << endl;
}