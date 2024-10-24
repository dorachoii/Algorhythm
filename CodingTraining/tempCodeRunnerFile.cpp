#include <iostream>
#include <string>

using namespace std;

int convert(int temperature, char key) {
    if (key == 'c') {
        int F = (temperature * 9 / 5) + 32;
        return F;
    }

    if (key == 'f') {
        int C = (temperature - 32) * 5 / 9;
        return C;
    }

    return 0; 
}

int main() {
    char key;
    int temperature;

    cout << "Press C to convert from F to C\n";
    cout << "Press F to convert from C to F\n";
    cin >> key;

    cout << "Your choice: " << key << endl;

    if (key == 'c') {
        cout << "Please enter the temperature in Fahrenheit: ";
        cin >> temperature;
        cout << "The temperature in Celsius is " << convert(temperature, 'c') << endl;
    } else if (key == 'f') {
        cout << "Please enter the temperature in Celsius: ";
        cin >> temperature;
        cout << "The temperature in Fahrenheit is " << convert(temperature, 'f') << endl;
    } else {
        cout << "Invalid choice! Please press 'C' or 'F'." << endl;
    }

}
