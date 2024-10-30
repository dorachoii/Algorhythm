#include <iostream>
#include <string>
using namespace std;

int main() {
    for(int i = 0; i < 13; i++){
        for(int j = 0; j <13; j++){
            cout << to_string(i) + "*" + to_string(j) + "=" + to_string(i*j) + "\n";
        }
    }
}
