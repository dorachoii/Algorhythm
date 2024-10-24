#include <iostream>
#include <string>

using namespace std;

string noun, verb, adjective, adverb;
int main() {
    cout << "Enter a noun: ";
    cin >> noun;
    cout << "Enter a verb: ";
    cin >> verb;
    cout << "Enter an adjective: ";
    cin >> adjective;
    cout << "Enter a adverb: ";
    cin >> adverb;

    cout << "Do you " + verb + " your " + adjective + " " + noun + " " + adjective + "? That's hilarious!"; 
}