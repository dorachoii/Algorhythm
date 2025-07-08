#include <iostream>
#include <string>
using namespace std;

int r;
int main() {

    while(r == 0 ){
        cout << "What is the rate of return?";
        cin >> r;
    }

    cout << "It will take " + to_string(72/r) + " years to double your initial investment.";
}