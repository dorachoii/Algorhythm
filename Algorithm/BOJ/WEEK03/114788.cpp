#include <bits/stdc++.h>
using namespace std;

string input;
vector<string> str;

string pc;

int main(){
    cin >> input;

    //순열, 조합
    int length = input.length();

    for(int i = 0; i<= length; i++){
        for(int j = 0; j <= length-i; j++){

            pc = input.substr(j,i);
            //cout << pc <<'\n';
            str.push_back(pc);
        }
    }
    //중복 지우기

    sort(str.begin(), str.end());
    str.erase((unique(str.begin(), str.end())), str.end());

    cout << str.size()-1;
    
}