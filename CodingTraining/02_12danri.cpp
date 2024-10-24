#include <iostream>
#include <string>

using namespace std;

float principal, interest, yearNum;

int main() {
    cout << "Enter the principal: ";
    cin >> principal;

    cout << "Enter the rate of interest: ";
    cin >> interest;

    cout << "Enter the number of years: ";
    cin >> yearNum;

    printf("After %.0f years at %.1f%%, the investment will be worth $%.2f\n", 
           yearNum, interest, principal * (1 + interest * yearNum));


}