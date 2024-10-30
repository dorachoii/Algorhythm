#include <iostream>
#include <string>
using namespace std;

string input;
vector<int> seconds;
int sum;
int main() {
    while(input != "done"){
        cout << "Enter a number: ";
        cin >> input;

        if(input == "done") break;
        seconds.push_back(stoi(input));
    }

    cout << "Numbers: ";
    for(int a : seconds){
        cout << to_string(a) + " ";
    }
    cout << "\n";

    sort(seconds.begin(), seconds.end());

    for(int a : seconds){
        sum += a;
    }

    int average = sum / seconds.size();

    for(int a : seconds){
        int b = a - average;
        sum += b*b;
    }

    int sd = sqrt(sum / seconds.size());

    cout << "The average is " + to_string(average) + "\n";
    cout << "The minimum is " + to_string(seconds[0])+ "\n";
    cout << "The maximum is " + to_string(seconds[seconds.size()-1])+ "\n";
    cout << "The standard deviation is "+ to_string(average);
    
}