#include <iostream>
#include <string>

using namespace std;

int num;

int main() {

    cout << "Please enter the number of the month: ";
    cin >> num;

    string month = "";

    switch(num){
        case 1: month = "January"; break;
        case 2: month = "Feburary"; break;
        case 3: month = "March"; break;
        case 4: month = "April"; break;
        case 5: month = "May"; break;
        case 6: month = "June"; break;
        case 7: month = "July"; break;
        case 8: month = "August"; break;
        case 9: month = "September"; break;
        case 10: month = "October"; break;
        case 11: month = "November"; break;
        case 12: month = "December"; break;
        default : month = "Invalid month"; break;
    }

    
    cout << "The name of the month is " + month;

}