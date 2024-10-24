#include <iostream>
#include <string>

using namespace std;

int people, pizza, pieces;

int main() {
    cout << "How many people?";
    cin >> people;
    cout << "How many pizzas do you have?";
    cin >> pizza;

    cout << "How many pieces are in a pizza?";
    cin >> pieces;

    int eachP = pizza * pieces / people;
    int leftover = pizza * pieces % people;

    cout << to_string(people) + " people with " + to_string(pizza) + " of pizza\n";
    cout << "Each person gets " + to_string(eachP) + " pieces of pizza\n";
    cout << "There are " + to_string(leftover) + " leftover pieces";
}