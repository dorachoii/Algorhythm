#include <iostream>
#include <string>
using namespace std;

int length, width;

int main() {

    cout << "What is the length of the room in feet?";
    cin >> length;
    cout << "What is the width of the room in feet?";
    cin >> width;

    cout << "You entered dimensions of " + to_string(length) + " feet by " + to_string(width) + " feet";
    cout << "The area is " + to_string(length * width) + " square feet\n";
    cout << to_string(length * 0.3048 * width * 0.3048) + "square meters";

}