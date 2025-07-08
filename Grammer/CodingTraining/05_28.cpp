#include <iostream>
#include <string>

using namespace std;
int a, sum;
int main() {
    for(int i = 0; i < 5; i++){
        cout << "Enter a number: ";
        cin >> a;
        sum += a;
    }

    cout << "The total is " + to_string(sum);
}