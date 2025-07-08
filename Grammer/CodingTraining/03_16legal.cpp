#include <iostream>
#include <string>

using namespace std;

int age, legalAge = 16;
int main() {
    cout << "What is your age?";
    cin >> age;

    if(age >= legalAge){
        cout << "You are old enough to legally drive.";
    }else{
        cout << "You are not old enough to legally drive.";
    }
}