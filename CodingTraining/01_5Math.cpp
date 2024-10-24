#include <iostream>
#include <string>

using namespace std;

string first, second;

int main() {
    cout << "What is the first number? ";
    cin >> first;
    cout << "What is the second number? ";
    cin >> second;

    int firstNum = stoi(first);
    int secondNum = stoi(second);

    cout << first + " + " + second + " = " + to_string(firstNum + secondNum) + "\n";
    cout << first + " - " + second + " = " + to_string(firstNum - secondNum) + "\n";
    cout << first + " * " + second + " = " + to_string(firstNum * secondNum) + "\n";
    cout << first + " / " + second + " = " + to_string(firstNum / secondNum) + "\n";
}