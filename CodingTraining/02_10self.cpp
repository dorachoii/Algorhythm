#include <iostream>
#include <string>

using namespace std;

float subTotal, tax, total;
int price[3], quantity[3];

int main() {
    cout << "Price of item 1: ";
    cin >> price[0];
    cout << "Quantity of item 1: ";
    cin >> quantity[0];
    cout << "Price of item 2: ";
    cin >> price[1];
    cout << "Quantity item 2: ";
    cin >> quantity[1];
    cout << "Price of item 3: ";
    cin >> price[2];
    cout << "Quantity item 3: ";
    cin >> quantity[2];

    for(int i = 0; i < sizeof(price); i++){
        subTotal += price[i] * quantity[i];
    }

    
    cout << "Subtotal: $";
    printf("%.2f", subTotal);
    cout << "\n";


    cout << "Tax: $";
    cin >> tax;
    cout << "Total: $" ;
    printf("%.2f", subTotal + tax);
}