#include <iostream>
#include <string>

using namespace std;

int orderAmount, subtotal;
float tax = 0.55;
string state;

int main() {

    cout << "What is the order amount?";
    cin >> orderAmount;

    cout << "What is the state?";
    cin >> state;

    if(state == "WI"){
        cout << "The subtotal is $" + to_string(orderAmount) + "\n";
        cout << "The tax is $";
        printf("%.2f",orderAmount + tax);
        cout <<"\n";
        cout << "The total is $";
        printf("%.2f",orderAmount + tax);

        return 0;
    }

    cout << "The total is $";
    printf("%.2f",orderAmount + tax);
    
}