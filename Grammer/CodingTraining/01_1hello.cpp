#include <iostream>
#include <string>
using namespace std;

// cin: 띄어쓰기 기준으로 받는다. 
// 하지만 enter전까지 입력받도록 해야한다.
// cin.get(): char 하나 가져옴
// cin.getline(입력스트림객체, string 객체, 구분자) : 구분자는 입력하지 않아도 됌.


string quote, writer;
int main() {
    cout << "What is the quote?\n";
    getline(cin, quote);

    cout << "Who said it?\n";
    getline(cin, writer);
    
    cout << writer + " says, \"" + quote + ".\"";

    return 0;
}