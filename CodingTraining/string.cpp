// string
// begin(), end()
// size()
// insert(위치, 문자열)
// erase(위치, 크기)
// pop_back()
// find(문자열)
// substr(위치, 크기)
// reverse()
// split()

// fill(), memset()
// sort()

// array, list, set, map, stack, queue, 

// scanf, printf
#include <iostream>
#include <string>
using namespace std;

int main() {
    string a = "love is ";
    a += " pain!";
    a.pop_back();

    cout << a << " : " << a.size() << "\n";
    cout << char(* a.begin()) <<'\n';
    cout << char(* (a.end() -1))<< '\n';

    a.insert(0, "test ");
    cout << a << " : " << "\n";

    a.erase(0,5);
    cout << a << " : " << a.size() << "\n";

    auto it = a.find("love");
    if(it != string::npos){
        cout << "포함되어 있다" << '\n';
    }
    cout << it << '\n';
    cout << string::npos << '\n';
    
    cout << a.substr(5,2) << '\n';

    return 0;
 }

 