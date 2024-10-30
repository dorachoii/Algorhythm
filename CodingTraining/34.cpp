#include <iostream>
#include <string>
using namespace std;

vector<string> employees;
string name;

int main() {
    cout << "There are 5 employees";
    for(int i = 0; i < 5; i++){
        cin >> name;
        employees.push_back(name);
    }

    cout << "Enter an employee name to remove:";
    cin >> name;

    for(int i = 0 ; i < employees.size(); i++){
        if(name == employees[i]) {
            employees.erase(employees.begin() + i);
        }
    }
    
    for(string pp : employees){
        cout << pp +"\n";
    }
}