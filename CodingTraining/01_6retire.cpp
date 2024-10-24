#include <iostream>
#include <string>

using namespace std;

string currentAge, retireAge;
int currentAgeNum, retireAgeNum, currentYear = 2024;

int main() {
    cout << "What is your current age? ";
    cin >> currentAge;
    cout << "At what age would you like to retire? ";
    cin >> retireAge;

    currentAgeNum = stoi(currentAge);
    retireAgeNum = stoi(retireAge);

    cout << "You have " + to_string(retireAgeNum - currentAgeNum) + " years left until you can retire.\n";
    cout << "It's " + to_string(currentYear) +", so you can retire in " + to_string(currentYear + (retireAgeNum - currentAgeNum)) + ".";

}

입출력 : cin, cout, getline(cin, string), to_string(), stoi();