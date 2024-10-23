#include <iostream>
using namespace std;

// cin: 띄어쓰기 기준으로 받는다. enter전까지 입력받도록 해야한다.

string quote, writer;
int main() {
    cout << "What is the quote?\n";
    quote = cin.get();

    cout << "Who said it?\n";
    writer = cin.get();
    
    cout << writer + " says, \"" + quote + ".\"";

    return 0;
}