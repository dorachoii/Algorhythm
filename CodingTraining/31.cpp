#include <iostream>
#include <string>
using namespace std;

int age, heartrate;
int main() {
    cout << "Age: ";
    cin >> age;
    cout << "Heartrate: ";
    cin >> heartrate;

    cout << "Resting Pulse: " + to_string(heartrate) + " Age: " + to_string(age) + "\n";
    cout << "Intensity    | Rate    \n";
    cout << "-------------|---------\n";
    
    for(int i = 55; i <= 95; i+=5){
        cout << to_string(i) + "%          | " + to_string(((220-age)-heartrate)*i+heartrate) + "bpm\n" ;
    }


}