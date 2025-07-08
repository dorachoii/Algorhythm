#include <iostream>
#include <string>

using namespace std;

int euros;
float exchangeRate;

int main() {
    cout << "How many Euros are you exchanging? ";
    cin >> euros;

    cout << "What is the exchange rate?";
    cin >> exchangeRate;

    cout << to_string(euros) + " Euros at an exchange rate of ";
    printf("%.2f",exchangeRate);
    cout << "is ";
    printf("%.2f", euros * exchangeRate/ 100);
    cout << " dollars";
}