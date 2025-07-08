#include <iostream>
#include <cstdlib> 
#include <ctime>
using namespace std;

string q;
string answer[] = {"yes","no", "maybe", "ask again later"};
int randomNum = 6;

int main() {
    srand(static_cast<unsigned int>(time(0)));

    getline(cin, q);

    randomNum = rand() % 4 ;
    
    cout  << answer[randomNum];
}