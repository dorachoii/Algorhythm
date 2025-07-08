#include <iostream>
#include <string>
using namespace std;

string pw;

int main() {
    cout << "What is the password: ";
    cin >> pw;

    if(pw == "asb$123"){
        cout << "Welcome!";
    }else{
        cout << "That password is incorrect.";
    }
}