#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
   int n;
   cin >> n;

   for(int i = 1; i <= n; i++){
    string s = "";

    for(int j = 0; j <n-i; j++){
        s += " ";
    }
    for(int k = 0; k< i; k++){
        s += "*";
    }
    cout << s << endl;

   }
}